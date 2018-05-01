/*
客户端程序
https://www.cnblogs.com/yinzhengjie/p/7261584.html
*/

package main

import(
	"net"
	"log"
	"fmt"
	"bufio"
	"os"
	"io"
)

var (
	cmd string
	line string
) 

func main(){
	addr := "118.24.105.92:8080"
	conn,err := net.Dial("tcp", addr)
	if err != nil {
		log.Fatal(err)
	}
	buf := make([]byte,10240)
	n,err := conn.Read(buf)
	if err != nil && err != io.EOF {
		log.Fatal(err)
	}
	fmt.Println(string(buf[:n]))
	
	f := bufio.NewReader(os.Stdin)
	for  {
			line,err = f.ReadString('\n')
			fmt.Sscan(line,&cmd)
			if len(line) == 1{
				continue
			}
			go sender(conn,line)
	}
	//conn.Close()
}

func sender(conn net.Conn, line string) {
	n, err := conn.Write([]byte(line))
	if err != nil {
		log.Fatal(err)
	}
	buf :=make([]byte,10)	
	for {
		n,err = conn.Read(buf)
		if err == io.EOF {
			conn.Close()
		}
		fmt.Print(string(buf[:n]))
	}
	//return
}