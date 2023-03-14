package main 

import (
	"fmt"
	"time"
	"log"
	)
func trace(msg string) func() {
	start := time.Now()
	log.Printf("enter %s", msg)
	return func() {
		log.Printf("exit %s (%s)", msg, time.Since(start))
	}
}
func test_trace() {
	fmt.Println("trace function, delay for 3 Seconds:")
	defer trace("Main function")()
	time.Sleep(3 * time.Second)
}
func double(x int) (result int) {
	defer func() {fmt.Printf("double(%d) = %d\n", x, result) } ()
	return x + x
}
func triple(x int) (result int) {
	defer func() {result += x }()
	return double(x)
}
func test_defer(){
	double(4)
	fmt.Println("tribple: ", triple(5))
}
func main() {
	test_defer()
	test_trace()
}