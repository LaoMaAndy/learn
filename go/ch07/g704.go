// Sleep
package main 

import (
	"flag"
	"fmt"
	"time"
	)

var period = flag.Duration("period", 1*time.Second, "sleep period")

func test_sleep(){
	flag.Parse()
	fmt.Printf("Sleeping for %v....", *period)
	time.Sleep(*period)
	fmt.Println()
}
type Celsius float64
type Fahrenheit float64
func CToF(c Celsius) Fahrenheit { return Fahrenheit(c*9/5 + 32)}
func FToC(f Fahrenheit) Celsius { return Celsius((f - 32) * 5 / 9)}
func (c Celsius) String() string { return fmt.Sprintf("%g°C", c)}
func (f Fahrenheit) String() string {return fmt.Sprintf("%g°F", f)}

type celsiusFlag struct { Celsius }
type Value interface {
	String() string
	Set(string) error
}
func (f *celsiusFlag) Set(s string) error {
	var unit string
	var value float64
	fmt.Sscanf(s, "%f%s", &value, &unit)
	switch unit {
	case "c", "C", "°C":
		f.Celsius = Celsius(value)
		return nil
	case "f", "F", "°F":
		f.Celsius = FToC(Fahrenheit(value))
		return nil
	}
	return fmt.Errorf("invalid temperature %q", s)
}
func CelsiusFlag(name string, value Celsius, usage string) *Celsius {
	f := celsiusFlag{value}
	flag.CommandLine.Var(&f, name, usage)
	return &f.Celsius
}
var temp = CelsiusFlag("temp", 20.0, "the temperature")
func test_temp(){
	flag.Parse()
	fmt.Println(*temp)
}
func main() {
	test_temp()
	//test_sleep()
}