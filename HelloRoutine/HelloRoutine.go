package main

import (
	"fmt"
	"time"
)

func main(){
	ch := make(chan string)
	for i :=0; i<5000; i++ {
		// go starts a goroutine
		go printHelloWorld(i,ch)
	}
	time.Sleep(time.Millisecond)
	for {
		msg := <-ch
		fmt.Println(msg)
	}
}

func printHelloWorld(i int, ch chan string) {
	for {
		ch <-fmt.Sprintf("Hello world from" + "goroutine %d\n", i)
	}
}