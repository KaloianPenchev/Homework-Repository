all: main.exe

main.exe: main/main.c linkedlist.o util.o
	gcc main/main.c linkedlist.o util.o -o main.exe

linkedlist.o: linked_list/linkedlist.c linked_list/linkedlist.h
	gcc -c linked_list/linkedlist.c -o linkedlist.o

util.o: util/util.c util/util.h
	gcc -c util/util.c -o util.o

clean:
	del /q *.o *.exe