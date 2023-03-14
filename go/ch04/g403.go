// Chapter 4.3 map
package main

import (
	"fmt"
	"sort"
)
func test_map() {
	ages := map[string]int {
		"alice":	31,
		"charlie":	34,
		"andy": 43,
		"fengnix": 40,
	}
	ages["bob"] = 20
	for i, v := range ages {
		fmt.Println(i, ": \t", v)
	}
	fmt.Println("----sort strings---")
	var names[] string
	for name := range ages {
		names = append(names, name)
	}
	sort.Strings(names)
	for _, name := range names {
		fmt.Printf("%s\t%d\n", name, ages[name])
	}
	// or use this way, more efficient
	names2 := make([]string, len(ages), len(ages))
	fmt.Println("len(names2) is :", len(names2))

	idx := 0
	for name := range ages {
		names2[idx] = name
		idx++
	}
	sort.Strings(names2)
	for _, name := range names2 {
		fmt.Printf("%s\t%d\n", name, ages[name])
	}
	
}
func empty_map(){
	ages := make(map[string]int)
	fmt.Println(ages == nil)
	fmt.Println(len(ages) == 0)
	ages["carol"] = 21
	if age, ok := ages["bob"]; !ok {
		fmt.Println("Don't exist bob")
	} else {
		fmt.Println("bos age: ", age)
	}
}
func equal(x, y map[string]int) bool {
	if len(x) != len(y) {
		return false
	}
	for k, xv := range x {
		if yv, ok := y[k]; !ok || yv != xv {
			return false
		}
	}
	return true
}
func main() {
	empty_map()
	//test_map()
	fmt.Println("----Chapter 4.3-----")
}