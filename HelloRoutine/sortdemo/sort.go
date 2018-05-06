package main
import (
	"sort"
	"fmt"
)

func main() {
	// Creates a slice of int
	a := []int {3,6,2,1,10,8}
	sort.Ints(a)

	for key,v := range a {
		fmt.Println(key,v)
	}
	fmt.Println("-----------我是华丽的分割线-------------------")
	for _,v := range a {
		fmt.Println(v)
	}
}