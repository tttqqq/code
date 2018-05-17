package main
import (
	"fmt"
)

func main(){
	argArr := []string{"hello","my","world","!"}
	printOut(argArr...)
}
func printOut(argArr...string){
	fmt.Println(argArr)
	println("真是赏心悦目!")
}