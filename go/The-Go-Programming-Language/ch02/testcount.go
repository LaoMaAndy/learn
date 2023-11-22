// Test popcount
package main

import (
	"fmt"
	"os"
	"popcount"
	"strconv"
)

func main() {
	for _, arg := range os.Args[1:] {
		v, err := strconv.ParseInt(arg, 10, 64)
		if err != nil {
			fmt.Fprintf(os.Stderr, "test: %v\n", err)
			os.Exit(1)
		}
		fmt.Printf("Popcount. %v\t : %v\n", arg, popcount.Count(uint64(v)))
	}
}
