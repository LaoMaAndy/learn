// Go data type
package main

import (
  "fmt"
  "os"
)

func main() {
  fmt.Println("This is a test")
  for _, para := range os.Args[1:] {
      fmt.Println(para)
  }
  fmt.Println("---go type----")
  gotype()
  fmt.Println("---go bit operate---")
  bitoper()
}

func gotype(){
  var n1 int16 = 123
  fmt.Printf ("%s: %v\n", "n1 is", n1)
  n2 := int32(234)
  fmt.Println (n2)
  var u uint8 = 255
  fmt.Println(u, u + 1, u * u)
  var i int8 = 127
  fmt.Println(i, i+1, i*i)
}

func bitoper() {
  var x uint8 = 1<<1 | 1<<5
  var y uint8 = 1<<1 | 1<<2

  fmt.Printf("%08b\n", x)
  fmt.Printf("%08b\n", y)

  fmt.Printf("%08b\n", x&y)
  fmt.Printf("%08b\n", x|y)
  fmt.Printf("%08b\n", x^y)
  fmt.Printf("%08b\n", x&^y)

  for i := uint(0); i < 8; i++ {
    if x&(1<<i) != 0{
      fmt.Println(i)
    }
  }

  fmt.Printf("%08b\n", x<<1)
  fmt.Printf("%08b\n", x>>1)
}
