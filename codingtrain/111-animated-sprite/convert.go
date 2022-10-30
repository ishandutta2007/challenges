package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"os"
	"path/filepath"
)

type Frame struct {
	Name     string
	Position Rect
}

type Rect struct {
	X, Y, W, H int
}

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	name := flag.Arg(0)
	frames, err := decode(name)
	check(err)

	txt := mkname(name, "txt")

	err = dump(txt, frames)
	check(err)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: spritesheet.json")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func decode(name string) ([]Frame, error) {
	var p struct {
		Frames []Frame
	}

	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	err = json.Unmarshal(data, &p)
	if err != nil {
		return nil, err
	}
	return p.Frames, nil
}

func dump(name string, frames []Frame) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	w := bufio.NewWriter(f)
	for _, p := range frames {
		r := p.Position
		fmt.Fprintf(w, "%v %v %v %v %v\n", p.Name, r.X, r.Y, r.W, r.H)
	}
	w.Flush()

	return f.Close()
}

func mkname(name, ext string) string {
	base := filepath.Base(name)
	bext := filepath.Ext(base)
	return fmt.Sprintf("%s.%s", base[:len(base)-len(bext)], ext)
}
