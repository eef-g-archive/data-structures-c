all: list_unit_test.c stack_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o list.exe list_unit_test.c list_files/node.c list_files/list.c
	gcc -Wall -Wextra -pedantic -std=c99 -o stack.exe stack_unit_test.c list_files/node.c list_files/list.c list_files/stack.c

list_test: list_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o list.exe list_unit_test.c list_files/node.c list_files/list.c
stack_test: stack_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o stack.exe stack_unit_test.c list_files/node.c list_files/list.c list_files/stack.c

.PHONY: clean

clean:
	rm main.exe
	rm list.exe
	rm stack.exe