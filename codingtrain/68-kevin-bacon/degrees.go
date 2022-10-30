package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

var (
	graphfile = flag.String("graphfile", "kevinbacon.json", "graph data file")
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	graph, err := load(*graphfile)
	if err != nil {
		log.Fatal(err)
	}

	from := flag.Arg(0)
	to := "Kevin Bacon"
	if flag.NArg() > 1 {
		to = flag.Arg(1)
	}
	paths := bfs(graph, from, to)
	fmt.Println(strings.Join(paths, " -> "))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: from [to]")
	flag.PrintDefaults()
	os.Exit(2)
}

type Graph struct {
	nodes []*Node
	links map[string]*Node
}

type Node struct {
	value    string
	edges    []*Node
	searched bool
	parent   *Node
}

func newgraph() *Graph {
	return &Graph{
		links: make(map[string]*Node),
	}
}

func (g *Graph) Reset() {
	for _, node := range g.nodes {
		node.searched = false
		node.parent = nil
	}
}

func (g *Graph) AddNode(node *Node) {
	g.nodes = append(g.nodes, node)
	g.links[node.value] = node
}

func (g *Graph) GetNode(value string) *Node {
	return g.links[value]
}

func (n *Node) AddEdge(neighbor *Node) {
	n.edges = append(n.edges, neighbor)
	neighbor.edges = append(neighbor.edges, n)
}

func load(name string) (*Graph, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	var db struct {
		Movies []struct {
			Title string
			Cast  []string
		}
	}
	err = json.Unmarshal(data, &db)
	if err != nil {
		return nil, err
	}

	graph := newgraph()
	for _, movie := range db.Movies {
		movienode := &Node{value: movie.Title}
		graph.AddNode(movienode)

		for _, cast := range movie.Cast {
			actornode := graph.GetNode(cast)
			if actornode == nil {
				actornode = &Node{value: cast}
			}
			graph.AddNode(actornode)
			movienode.AddEdge(actornode)
		}
	}

	return graph, nil
}

func bfs(graph *Graph, from, to string) []string {
	graph.Reset()

	start := graph.GetNode(from)
	end := graph.GetNode(to)
	if start == nil || end == nil {
		return nil
	}

	start.searched = true
	queue := []*Node{start}
	for ; len(queue) > 0; queue = queue[1:] {
		current := queue[0]
		if current == end {
			break
		}
		for _, neighbor := range current.edges {
			if !neighbor.searched {
				neighbor.searched = true
				neighbor.parent = current
				queue = append(queue, neighbor)
			}
		}
	}

	nodes := []*Node{end}
	for next := end.parent; next != nil; next = next.parent {
		nodes = append(nodes, next)
	}

	paths := []string{}
	for i := len(nodes) - 1; i >= 0; i-- {
		paths = append(paths, nodes[i].value)
	}
	return paths
}
