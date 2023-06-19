// Chapter 7.5
package main 

import (
	"bytes"
	"fmt"
	"io"
	"os"
	)

func test_face() {
	var w io.Writer
	w = os.Stdout
	w.Write([]byte("hello\n"))
	b := new(bytes.Buffer)
	w = b
	w.Write([]byte("buffer"))
	fmt.Println(b)
}


func main() {
	test_face()
}