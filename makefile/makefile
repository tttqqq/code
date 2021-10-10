main:main.o print_my1.o print_my2.o
	gcc -o main main.o print_my1.o print_my2.o

main.o:main.c print_my1.h print_my2.h
	gcc -Wall -g -c main.c

print_my1.o:print_my1.c print_my1.h
	gcc -Wall -g -c print_my1.c

print_my2.o:print_my2.c print_my2.h
	gcc -Wall -g -c print_my2.c

clean:
	rm -f *.o main