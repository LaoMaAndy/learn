// echo server
package main 

import (
	"fmt"
	"log"
	"net"
	"strings"
	"time"
	"bufio"
)

func echo(c net.Conn, shout string, delay time.Duration) {
	time.Sleep(delay)
	fmt.Fprintln(c, "\t", strings.ToUpper(shout))
	time.Sleep(delay)
	fmt.Fprintln(c, "\t", shout)
	time.Sleep(delay)
	fmt.Fprintln(c, "\t", strings.ToLower(shout))
}
func handleConn(c net.Conn) {
	input := bufio.NewScanner(c)
	for input.Scan() {
		echo(c, input.Text(), 1*time.Second)
	}
	c.Close()
}
func go_clock() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil  {
		log.Fatal(err)
	}
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}
func main() {
	go_clock()
	fmt.Println("it's a clock.")
}