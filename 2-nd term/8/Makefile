all: main.exe

LinkedList.o: LinkedList.h LinkedList.c
	gcc -c LinkedList.c -o LinkedList.o

main.exe: main.c LinkedList.o
	gcc main.c LinkedList.o -o main.exe

clean:
	del /q *.o *.exe