all: prog

OBJECTS = main.o temp_api.o

prog: $(OBJECTS)
	gcc -o prog $(OBJECTS)

main.o: main.c temp_api.h
	gcc -c -o main.o main.c -I temp_api.h

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	del prog.exe $(OBJECTS)
