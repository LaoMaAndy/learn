//ColoredPoint
package main

import (
	"fmt"
	"image/color"
	"math"
	)
type Point struct {X, Y float64}
func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}
func (p Point) Add(q Point) Point { return Point{p.X + q.X, p.Y + q.Y}}
func (p Point) Sub(q Point) Point { return Piont{p.X - q.X, p.Y - q.Y}}
type Path []Point
func (path Path) TranslateBy(offset Point, add bool) {
	var op func(p, q Point) Point
	if add {
		op = Point.Add
	} else {
		op = Point.Sub
	}
	for i := range path {
		path[i] = op(path[i], offset)
	}
}
type ColoredPoint struct {
	Point
	Color color.RGBA
}
func test_color() {
	var cp ColoredPoint
	cp.X = 1
	fmt.Println(cp.Point.X)
	cp.Point.Y = 2
	fmt.Println(cp.Y)
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var p = ColoredPoint{Point{1, 1}, red}
	var q = ColoredPoint{Point{5, 4}, blue}
	fmt.Println(p.Distance(q.Point))
	p.ScaleBy(2)
	q.ScaleBy(2)
	fmt.Println(p.Distance(q.Point))
}
func test_value() {
	p := Point{1, 2}
	q := Point{4, 6}
	disFromP := p.Distance
	fmt.Println(disFromP(q))
	var origin Point
	fmt.Println(disFromP(origin))
	scaleP := p.ScaleBy
	scaleP(2)
	fmt.Println(p)
	scaleP(3)
	fmt.Println(p)
	scaleP(4)
	fmt.Println(p)
}
func test_exp(){
	p := Point{1, 2}
	q := Point{4, 6}
	dist := Point.Distance
	fmt.Println(dist(p, q))
	fmt.Printf("%T\n", dist)

	scale := (*Point).ScaleBy
	scale(&p, 2)
	fmt.Println(p)
	fmt.Printf("%T\n", scale)
}
func main() {
	test_exp()
	test_value()
	test_color()
}
