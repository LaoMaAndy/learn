//Chapter 5.05
package main 

import (
	"fmt"
	"strings"
)
func square(n int) int { return n * n }
func negative(n int) int { return -n}
func product(m, n int) int { return m * n }

func test_fuc(){
	f := square
	fmt.Println(f(3))

	f = negative
	fmt.Println(f(3))
	fmt.Printf("%T\n", f)
	//f = product
	fmt.Println("call a function which value is nil, will cause a panic error:")
	var g func(int) int
	if g == nil {
		fmt.Printf("%T : ecqual nil.\n", g)
	}
}
func add1(r rune) rune { return r + 1}
func test_add1() {
	fmt.Println(strings.Map(add1, "HAL-9000"))
	fmt.Println(strings.Map(add1, "VMS"))
	fmt.Println(strings.Map(add1, "Admix"))
}
func squares() func() int {
	var x int
	return func() int {
		x++
		return x * x
	}
}
func test_squares() {
	f := squares()
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
}
func sum(vals...int) int {
	total := 0
	for _, val := range vals {
		total += val
	}
	return total 
}
func test_sum() {
	fmt.Println(sum())
	fmt.Println(sum(3))
	fmt.Println(sum(1, 2, 3, 4, 5, 6))
	values := []int{1, 2 , 3, 4, 5}
	fmt.Println(sum(values...))
}
func f(...int){}
func g([]int){}
func test_func2(){
	fmt.Printf("%T\n", f)
	fmt.Printf("%T\n", g)
}

func main() {
	test_func2()
	test_sum()
	test_squares()
	test_add1()
	test_fuc()
}
