package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"sort"
)

type Relation struct {
	Name  string
	Score float64
}

type User struct {
	Timestamp       string
	Name            string
	I, II, III      int
	IV, V, VI, VII  int
	Rogue1, Holiday int
}

var flags struct {
	corpus string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("nearest-neighbor: ")
	parseflags()

	db, err := load(flags.corpus)
	check(err)

	rel := neighbors(db, flag.Arg(0))
	fmt.Printf("%s\n", flag.Arg(0))
	for _, r := range rel {
		fmt.Printf("%-32s %.12f\n", r.Name, r.Score)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] name")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.Usage = usage
	flag.StringVar(&flags.corpus, "corpus", "movies.json", "specify corpus file")
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func load(name string) (map[string]User, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	var p struct {
		Users []User
	}
	err = json.Unmarshal(data, &p)
	if err != nil {
		return nil, err
	}

	m := make(map[string]User)
	for _, u := range p.Users {
		m[u.Name] = u
	}

	return m, nil
}

func neighbors(db map[string]User, name string) []Relation {
	var r []Relation
	for xname := range db {
		if name == xname {
			continue
		}
		r = append(r, Relation{
			Name:  xname,
			Score: similarity(db, name, xname),
		})
	}

	sort.SliceStable(r, func(i, j int) bool {
		return r[i].Score > r[j].Score
	})

	return r
}

func similarity(db map[string]User, name1, name2 string) float64 {
	p, f1 := db[name1]
	q, f2 := db[name2]
	if !f1 || !f2 {
		return -1
	}

	x := ratings(&p)
	y := ratings(&q)
	s := 0
	for i := range x {
		if x[i] != 0 && y[i] != 0 {
			s += (x[i] - y[i]) * (x[i] - y[i])
		}
	}
	d := 1 / (1 + math.Sqrt(float64(s)))

	return d
}

func ratings(u *User) []int {
	return []int{u.I, u.II, u.III, u.IV, u.V, u.VI, u.VII, u.Rogue1, u.Holiday}
}
