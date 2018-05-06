package main

import (
	"fmt"
	"PipelineRoutineSort/pipeline"
)

func main() {
	p := pipeline.ArraySource(3,2,6,7,4)
	for v := range p {
		fmt.Println(v)
	}
	
	fmt.Println("---------华丽的分割线1-------------")
	p1 := pipeline.InMemSort(pipeline.ArraySource(3,2,6,7,4))
	for {
		if num,ok := <-p1; ok {
			fmt.Println(num)
		} else {
			break
		}
	}

	fmt.Println("---------华丽的分割线2-------------")
	p2 := pipeline.Merge(
		pipeline.InMemSort(
			pipeline.ArraySource(
				3,2,6,7,4)),
		pipeline.InMemSort(
			pipeline.ArraySource(
				6,2,5,8,1,14,11,10)))
	for v := range p2 {
		fmt.Println(v)
	}
}