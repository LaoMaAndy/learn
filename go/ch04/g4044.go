// Define a struct
package main 

import (
	"fmt"
	)
type Point struct {
	X, Y int
}
type Circle struct {
	Point
	Radius int
}
type Wheel struct {
	Circle
	Spokes int
}
func main() {
	var w Wheel
	w = Wheel {
		Circle: Circle{
			Point: Point{X: 8, Y: 8},
			Radius: 5,
		},
		Spokes: 20,
	}
	fmt.Println("Print %#v:")
	fmt.Printf("%#v\n", w)
	w.X = 42
	fmt.Printf("%#v\n", w)
	fmt.Println("Print %v:")
	fmt.Printf("%v\n", w)
	w.X = 65
	fmt.Printf("%v\n", w)
}
