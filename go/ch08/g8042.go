//Chapter 8042
package main 

import "fmt"

func counter(out chan<- int) {
	for x := 0; x < 100; x++ {
		out <- x
	}
	close(out)
}
func squarer(out chan<- in, in <-chan int) {
	for v := range in {
		out <- v * v
	}
	close(out)
}
func printer(in <-chan int) {
	for v := range in {
		fmt.Println(v)
	}
}
func test_pip2(){
	nat := make(chan in)
	sqr := make(chan int)
	go counter(nat)
	go squarer(sqr, nat)
	printer(sqr)
}
func main() {
	//test_pip1()
	test_pip2()
}
func test_pip1(){
	nat := make(chan int)
	sqr := make(chan int)
	// Counter
	go func() {
		for x := 0; x < 100; x++ {
			nat <- x
		}
		close(nat)
	}()
	//Squarer
	go func() {
		for x := range nat{
			sqr <- x * x
		}
		close(sqr)
	}()
	//Printer(int main goroutine)
	for x := range sqr{
		fmt.Println(x)
	}
}