//Chapter 6.1
package main

import (
	"math"
	"fmt"
	)

type Point struct { X, Y float64}

// traditional function
func Distance(p, q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}
// same thing, but as a method of the Point type
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

type Path []Point

func (p Path) Distance() float64{
	sum := 0.0
	for i := range p {
		if i > 0 {
			sum += p[i-1].Distance(p[i])
		}
	}
	return sum
}
func test_func() {
	perim := Path {
		{1, 1},
		{5, 1},
		{5, 4},
		{1, 1},
	}
	fmt.Println(perim.Distance())
}
func (p *Point) ScaleBy(factor float64){
	p.X *= factor
	p.Y *= factor
}
func test_scale() {
	pp := &Point{3, 4}
	n1 := Point{10, 50}
	n2 := Point{100, 300}
	pp.ScaleBy(5)
	fmt.Println(*pp)
	(&n1).ScaleBy(5)
	fmt.Println(n1)
	p2 := &n2
	p2.ScaleBy(5)
	fmt.Println(n2)
	n1.ScaleBy(30)
	fmt.Println(n1)
}
type IntList struct {
	Value int
	Tail *IntList
}
func (list *IntList) Sum() int {
	if list == nil {
		return 0
	}
	return list.Value + list.Tail.Sum()
}
func test_intlist() {
	n1 := IntList{1, nil}
	n2 := IntList{2, &n1}
	n3 := IntList{3, &n2}
	nptr := &n3
	fmt.Println(nptr.Sum())
}
func main() {
	test_intlist()
	test_scale()
	test_func()
}
