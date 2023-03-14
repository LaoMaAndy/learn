// Chapter 402, Slice
package main 

import (
	"fmt"
	)
func slic() {
	months := [...]string{1: "January", 2: "February", 3: "March", 4: "April", 5: "May", 6: "June", 
					7: "July", 8: "August", 9: "September", 10: "October", 11: "November", 12: "December"}
	q2 := months[4:7]
	summber := months[6:9]
	fmt.Println(q2)
	fmt.Println(summber)
}
func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
func test_reverse() {
	a := [...]int {0, 1, 2, 3, 4, 5}
	reverse(a[:])
	fmt.Println(a)
}
func rot() {
	s := []int{0, 1, 2, 3, 4, 5}
	reverse(s[:2])
	reverse(s[2:])
	reverse(s)
	fmt.Println(s)
}
func chang() {
	 a := []int{0, 1, 2, 3, 4, 5, 6, 7}
	 fmt.Println("The Source data: ", a)
	 a[0], a[1], a[2], a[3] = a[4], a[5], a[6], a[7]
	 fmt.Println("After slice it : ", a)
	 b := []byte("abcdefg")
	 b[0] = 0
	 fmt.Println(b)
}
func capa() {
	 a := []int{0, 1, 2, 3, 4, 5, 6, 7}
	 fmt.Println("a: ", a)
	 fmt.Println("len: ", len(a))
	 fmt.Println("cap: ", cap(a))
	 b := a[3:5]
	 fmt.Println("b: ", b)
	 fmt.Println("len: ", len(b))
	 fmt.Println("cap: ", cap(b))
}
func mak() {
	a := make([]int, 20)
	fmt.Println("make a slice: ", a)
	b := make([]rune, 10, 40)
	fmt.Println("make another slice: ", b)
	fmt.Println("cap: ", cap(b), "len: ", len(b))
}
func test_nil(){
	var s[]int
	fmt.Println("s :", s, "len(s) :", len(s), "cap(s)", cap(s))
	s = nil 
	fmt.Println("s :", s, "len(s) :", len(s), "cap(s)", cap(s))
	s = []int(nil)
	fmt.Println("s :", s, "len(s) :", len(s), "cap(s)", cap(s))
	s = []int{1}
	fmt.Println("s :", s, "len(s) :", len(s), "cap(s)", cap(s))
}
func test_append() {
	var runes []rune
	for _, r := range "Hello, 世界" {
		runes = append(runes, r)
	}
	fmt.Printf("%q\n", runes)
}
func appendInt(x []int, y int) []int {
	var z []int
	zlen := len(x) + 1
	if zlen <= cap(x) {
		z = x[:zlen]
	} else {
		zcap := zlen
		if zcap < 2*len(x) {
			zcap = 2 *len(x)
		}
		z = make([]int, zlen, zcap)
		copy(z, x)
	}
	z[len(x)] = y
	return z
}
func test_appint() {
	var x, y []int
	for i := 0; i < 10; i++ {
		y = appendInt(x, i)
		fmt.Printf("%d cap=%2d\t%v\n", i, cap(y), y)
		x = y
	}
}
func test_slice() {
	ints := []int{1, 2, 3, 4, 5, 6, 7, 8 , 9, 10}
	fmt.Println("------test slice")
	fmt.Println("Orangin array: ", ints)
	sla := ints[0:3]
	sla[0] = 100
	fmt.Println(ints)
	fmt.Println("len(ints): ", len(ints))
	fmt.Println("cap(ints): ", cap(ints))
	fmt.Println("len(sla) :", len(sla))
	fmt.Println("cap(sla) :", cap(sla))
	bs := ints[:]
	sla[1] = 1000
	fmt.Println("sla[1]=100, then bs=", bs)
	cs := append(sla, 555)
	fmt.Println("append(sla, 555): ", sla)
	fmt.Println("append(sla, 555): ", cs)
	fmt.Println("sla[1]=100, then bs=", bs)
	ds := append(ints[0:len(ints)], 999)
	fmt.Println("append(ints[0:len(ints)], 999), then ds=", ds)
	es := ints[:]
	fmt.Println("append(ints[0:len(ints)], 999), then bs=", bs)
	fmt.Println("append(ints[0:len(ints)], 999), then es=", es)
	ds[0] = 800
	fmt.Println("ds[0] = 1000, then bs=", ds)
	fmt.Println("ds[0] = 1000, then es=", bs)
	fmt.Println("len(ints): ", len(ints), "cap(ints): ", cap(ints))
	fmt.Println("len(ds): ", len(ds), "cap(ds): ", cap(ds))
	for i := 0; i < len(ds); i++ {
		ds[i] = 0
	}
	fmt.Println(ds)
	fmt.Println(ints)
}
func nonempty(str []string) []string {
	i := 0
	for _, s := range str {
		if s != "" {
			str[i] = s
			i++
		}
	}
	return str[:i]
}
func test_nonempty() {
	data := []string{"0ne", "", "tree"}
	fmt.Printf("%q\n", nonempty(data))
	fmt.Printf("%q\n", data)
}
func nonempty2(str []string) []string {
	out := str[:0]
	for _, s := range str {
		if s != "" {
			out = append(out, s)
		}
	}
	return out
}
func test_nonempty2() {
	data := []string{"first", "", "third"}
	fmt.Printf("%q\n", nonempty(data))
	fmt.Printf("%q\n", data)
}
func remove(s []int, i int) []int {
	copy(s[i:], s[i+1:])
	return s[:len(s)-1]
}
func test_remove() {
	a := []int{1, 2, 3, 4, 6}
	fmt.Println("Origin: ", a)
	fmt.Println("After remove:", remove(a[:], 2))
}
func remove2(s []int, i int) []int {
	s[i] = s[len(s)-1]
	return s[:len(s)-1]
}
func test_remove2() {
	s := []int{10, 11, 12, 13, 14}
	fmt.Println(s)
	fmt.Println(remove2(s, 6))
}
// Main function
func main() {
	test_remove2()
	//test_remove()
	//slic()
	//test_reverse()
	//rot() 
	//chang()
	//capa()
	//mak()
	//test_nil()
	//test_append()
	//test_appint()
	//test_slice()
	//test_nonempty()
	//test_nonempty2()
}
