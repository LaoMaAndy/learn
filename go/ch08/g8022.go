// // Clock1 is a TCP server that periodically writes the time.
package main 

import (
	"fmt"
	"io"
	"log"
	"net"
	"time"
	)

func handleConn(c net.Conn) {
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			return
		}
		time.Sleep(1 *time.Second)
	}
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