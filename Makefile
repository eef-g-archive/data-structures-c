all: main.c
	gcc -Wall -Wextra -pedantic -std=c99 -o main.exe main.c list_files/node.c list_files/list.c list_files/stack.c
list_test: list_unit_test.c
	gcc -Wall -Wextra -predantic -std=c99 -o list.exe list_unit_test.c list_files/node.c list_files/list.c

.PHONY: clean
clean:
	rm main.exe
	rm list.exe