
all: main.c
	gcc -Wall -Wextra -pedantic -std=c99 -o main.exe main.c list_files/node.c list_files/list.c list_files/stack.c
.PHONY: clean
clean:
	rm main.exe
