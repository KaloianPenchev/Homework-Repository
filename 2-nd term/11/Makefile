all: serializer.exe deserializer.exe

serializer.exe: serializer.c error.o
	gcc serializer.c error.o -o serializer.exe

deserializer.exe: deserializer.c error.o
	gcc deserializer.c error.o -o deserializer.exe

error.o: error/error.c error/error.h
	gcc -c error/error.c -o error.o

clean:
	del /f /q *.o *.exe  