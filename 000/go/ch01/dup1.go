// Dup1 prints the text of each line that appears more than once int the standard input
// precedee by its count
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	count := make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		count[input.Text()]++
	}
	for line, n := range count {
		if n > 1 {
			fmt.Printf("%d\t%s\n", n, line)
		}
	}
}
