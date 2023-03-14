// Chapter 4.1
package main

import (
  "fmt"
)

func main() {
  arra()
  arra_init()
}

func arra(){
  var a [3]int
  var q [3]int = [3]int{1, 2, 3}
  var r [3]int = [3]int{100, 200}
  p := [...]int {10, 20, 30}

  for i, v := range a {
    fmt.Printf("%d %d\n", i, v)
  }
  for i := 0; i < 3; i++ {
    fmt.Printf("p: %d, q: %d, r: %d\n", p[i], q[i], r[i])
  }
}
func arra_init() {
  type Currency int
  const (
    USD Currency = iota
    EUR
    GBP
    RMB
  )
  symbol := [...]string{USD: "$", EUR: "€", GBP: "£", RMB: "¥"}
  fmt.Println(RMB, symbol[RMB])
}
