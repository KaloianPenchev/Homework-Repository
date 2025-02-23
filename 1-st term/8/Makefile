all: taskmanager.exe

taskmanager.exe: processes.o
	gcc taskmanager.c processes.o -o taskmanager.exe

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

clean:
	del /q *.o *.exe