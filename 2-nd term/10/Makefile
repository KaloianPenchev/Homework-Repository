all: main.exe fill_with_example_data.exe

fill_with_example_data.exe: main/fill_with_example_data.c error.o compress_util.o
	gcc main/fill_with_example_data.c error.o compress_util.o -o fill_with_example_data.exe

main.exe: main/main.c linkedlist.o error.o compress_util.o
	gcc main/main.c linkedlist.o error.o compress_util.o -o main.exe

linkedlist.o: linked_list/linkedlist.c linked_list/linkedlist.h
	gcc -c linked_list/linkedlist.c -o linkedlist.o

error.o: error/error.c error/error.h
	gcc -c error/error.c -o error.o

compress_util.o: compress_util/compress_util.c compress_util/compress_util.h
	gcc -c compress_util/compress_util.c -o compress_util.o

clean:
	del /q *.o *.exe