// Chapter 4.4 struct
package main 

import (
	"fmt"
	"time"
	)

type Employee struct {
	ID 			int
	Name		string
	Address		string 
	Dob			time.Time
	Position	string
	Salary		int
	ManagerID	int
}

var dilbert Employee

func test_struct() {
	var empMonth *Employee = &dilbert
	dilbert.Salary = 2000
	empMonth.Position += " (proactive team player)"
	fmt.Println(dilbert)
}

func main() {
	test_struct()
	fmt.Println("---chapter 4.4---")
}

