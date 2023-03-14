//Chapter 5.1 function 
package main 

import ( 
	"fmt"
	"math"
	)

func hypot(x, y float64) float64 {
	return math.Sqrt(x*x + y*y)
}
func test_hypot(){
	fmt.Println(hypot(3, 4))
}
func add(x int, y int) int { return x + y }
func sub(x, y int) (z int) { z = x - y; return}
func first(x int, _ int) int { return x}
func zero(int, int) int { return 0}
func test_func() {
	fmt.Printf("%T\n", add)
	fmt.Printf("%T\n", sub)
	fmt.Printf("%T\n", first)
	fmt.Printf("%T\n", zero)
}
func main() {
	test_func()
	test_hypot()
	fmt.Println("Chapter 5.1")
}