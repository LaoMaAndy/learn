//Chapter 5.9 Panic
package main 

import (
	"fmt"
	"os"
	"runtime"
	)

func f(x int) {
	fmt.Printf("f(%d)\n", x+0/x)
	defer func() {
		if p := recover(); p != nil {
			err := fmt.Errorf("internal error: %v", p)
			fmt.Errorf("%s\n", err)
			fmt.Printf("defer %d\n", x)
			}
		}()
	f(x - 1)
}
func printStack() {
	var buf [4096]byte
	n := runtime.Stack(buf[:], false)
	os.Stdout.Write(buf[:n])
}
func main() {
	defer printStack()
	f(3)
}