package main 

import (
	"fmt"
	"time"
	)
func spinner(delay time.Duration) {
	for {
		for _, r := range `-\|/` {
			fmt.Printf("\r%c", r)
			time.Sleep(delay)
		}
	}
}
func fib(x int) int {
	if x < 2 {
		return x
	}
	return fib(x-1) + fib(x-2)
}
func test_fib() {
	go spinner(100 * time.Millisecond)
	const n = 40
	fibN := fib(n)
	fmt.Printf("\rFibonacci(%d) = %d\n", n, fibN)
}
func test_r() {
	fmt.Printf("%s", "This is a test")
	fmt.Printf("%s", "\r")
}
func main() {
	test_r()
	//test_fib()
	fmt.Println("Chapter 801")
}