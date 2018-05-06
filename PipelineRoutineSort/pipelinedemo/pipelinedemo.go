package main

import (
	"bufio"
	"os"
	"fmt"
	"PipelineRoutineSort/pipeline"
)
func basetest() {
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


func main() {
	basetest()
	const name = "large.in"
	const number = 100000000
	file,err := os.Create(name)
	if err != nil {
		panic(err)
	}
	 
	defer file.Close()

	p := pipeline.RandomSource(number)
	writer := bufio.NewWriter(file) //加快读写速度
	pipeline.WriterSink(writer,p)
	writer.Flush() //保证生成要求的文件大小
	file, err = os.Open(name)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	p = pipeline.ReaderSource(bufio.NewReader(file))
	count := 0
	for v := range p {
		fmt.Println(v)
		count++
		if count >100 {
			break
		}
	}
/* 	name := "mini.in"
	number := 8
	in,out := make(chan int)
	in  <- pipeline.RandomSource(number)
	pipeline.WriteSink(name,in)

	for v := range out {
		v <- pipeline.ReaderSource(name)
		fmt.PrintLn(v)
	} */

}