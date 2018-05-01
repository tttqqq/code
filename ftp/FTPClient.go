/*
服务器程序
https://www.cnblogs.com/yinzhengjie/p/7261584.html
*/

package main

import (
	"net"
	"log"
	"io"
	"fmt"
	"bufio"
	"strings"
	"os"
	"path/filepath"
	"io/ioutil"
)

var (
	cmd string
	file_name string
)

func main(){
	addr :="0.0.0.0:8080"
	listener,err :=net.Listen("tcp",addr)
	if err != nil {
	log.Fatal(err)
	}
	defer listener.Close()
	conn,err :=listener.Accept()
	if err != nil {
	log.Fatal(err)
	}
	conn.Write([]byte("欢迎使用陈涛权开发的FTP编程服务器!"))
	r :=bufio.NewReader(conn)
	for {
		line,err := r.ReadString('\n') //将r的内容按照换行符读取。
		if err != io.EOF {
			conn.Close()
		}
		fmt.Print(line)
		line  =  strings.TrimSpace(line)
		fmt.Println(len(strings.Fields(line)))
		if len(line) == 0 {
			continue
		}
		cmd = strings.Fields(line)[0]
		if len(strings.Fields(line)) >1 {
			file_name = strings.Fields(line)[1]
		}
		pwd,err := os.Getwd()
		if err != nil {
			panic("获取路径出错!")	
		}
		file_name = filepath.Join(pwd,file_name)
		fmt.Println(file_name)
		switch cmd{
		case "GET","get":
			f,err := os.Open(file_name)
			if err != nil {
				fmt.Println(err)
			}
			defer f.Close()
			buf,err := ioutil.ReadAll(f)
			if err != nil {
			log.Print(err)
			return
			}
			conn.Write(buf)
		case "PUSH","push":
			fmt.Println("上传文件的语句")
			conn.Write([]byte("上传文件的命令\n"))
		case "EXIT","exit":
			return
		default:
			fmt.Println("你输入的命令无效")
			conn.Write([]byte("你输入的指令有问题\n"))
		}
	}
}
