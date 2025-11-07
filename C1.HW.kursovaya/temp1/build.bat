chcp 1251
gcc -c --std=c99 -o main.o main.c
gcc -c --std=c99 -o temp_api.o temp_api.c
gcc -o prog main.o temp_api.o
# pause
.\prog.exe