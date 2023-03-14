// ch3-05 string
package main

import (
  "fmt"
  "os"
  "unicode/utf8"
  "strings"
  "bytes"
  "strconv"
)
func main() {
  echo()
  fstr()
  utf()
  testBasename()
  testcomma()
  test_itos()
  test_conv()
}
func echo(){
  for _, arg := range os.Args[0:] {
    fmt.Println(arg)
  }
}
func fstr() {
  s := "hello, world"
  fmt.Println(len(s))
  fmt.Println(s[0], s[7])
  //c := s[len(s)]
  //fmt.Println(c)
  fmt.Println(s[0:5])
  fmt.Println(s[7:])
  fmt.Println(s[:])
  const s1 = `Go is a tool for managing Go source code.
  Usage:
    go command [arguments]
    ...`
  fmt.Println(s1)
  fmt.Println("-----UTF8-------")
}
func utf() {
  s := "Hello, 世界"
  fmt.Println(len(s))
  fmt.Println(utf8.RuneCountInString(s))

  for i := 0; i < len(s); {
    r, size := utf8.DecodeRuneInString(s[i:])
    fmt.Printf("%d\t%c\n", i, r)
    i += size
  }
  fmt.Println("---for...range---")
  for i, r := range s {
    fmt.Printf("%d\t%q\t%d\n", i, r, r)
  }
  s1 := "プログラム"
  fmt.Printf("% x\n", s1)
  r := []rune(s1)
  fmt.Printf("%x\n", r)
  fmt.Println(string(r))
  fmt.Println(string(65))
  fmt.Println(string(0x4eac))
  fmt.Println(string(1234567))
  sa := "This a"
  sb := "test"
  var sc string = sa + " " + sb
  //sc[0] = 'i'   // error: string is read-only
  fmt.Println(sa)
  fmt.Println(sb)
  fmt.Println(sc)
  fmt.Println("---testBasename----")
}
func testBasename() {
  str := []string{"this", "this.go", "a/b/this.go", "a/b/this.c.go"}
  for i, s := range str {
    fmt.Printf("%d %-15v %-10v %-10v\n", i, s, basename(s), basename1(s))
  }
}
//basename removes directory components and a .suffix.
// e.g., a => a, a.go => a, a/b/c.go => c, a/b.c.go => b.c
func basename(s string) string {
  // Discard last '/' and everything before.
  for i := len(s) - 1; i >= 0; i-- {
    if (s[i] == '/') {
      s = s[i+1:]
      break
    }
  }
  // Preserve everything before last '.'.
    for i := len(s) - 1; i >= 0; i-- {
      if s[i] == '.' {
        s = s[:i]
        break
      }
    }
    return s
}
func basename1(s string) string {
  slash := strings.LastIndex(s, "/")
  s = s[slash+1:]
  if dot := strings.LastIndex(s, "."); dot >= 0 {
    s = s[:dot]
  }
  return s
}

func testcomma() {
  fmt.Println("---testcomma----")
  s := "1234567890"
  fmt.Printf("%12s: %s\n", s, comma(s))
  fmt.Printf("%s\n", s)
}
// comma inserts commas in a non-negative decimal integer string.
func comma(s string) string {
  n := len(s)
  if n <= 3 {
    return s
  }
  return comma(s[:n-3]) + "," + s[n-3:]
}
// intsToString is like fmt.Sprint(values) but adds commas.
func intsToString(values []int) string {
  var buf bytes.Buffer
  buf.WriteByte('[')
  for i, v := range values {
    if i > 0 {
      buf.WriteString(", ")
    }
    fmt.Fprintf(&buf, "%d", v)
  }
  buf.WriteByte(']')
  return buf.String()
}
func test_itos() {
  fmt.Println(intsToString([]int{1,2,3,}))
}
//Convert a string to number
func test_conv() {
   x := 123
   y := fmt.Sprintf("%d", x)
   fmt.Println(y, strconv.Itoa(x))
}
