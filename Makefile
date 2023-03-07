all: tests/list_unit_test.c tests/stack_unit_test.c tests/queue_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o list.exe tests/list_unit_test.c src/node.c src/list.c
	gcc -Wall -Wextra -pedantic -std=c99 -o stack.exe tests/stack_unit_test.c src/node.c src/list.c src/stack.c
	gcc -Wall -Wextra -pedantic -std=c99 -o queue.exe tests/queue_unit_test.c src/node.c src/list.c src/queue.c

list_test: tests/list_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o list.exe tests/list_unit_test.c src/node.c src/list.c

stack_test: tests/stack_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o stack.exe tests/stack_unit_test.c src/node.c src/list.c src/stack.c

queue_test: tests/queue_unit_test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o queue.exe tests/queue_unit_test.c src/node.c src/list.c src/queue.c

lib_test: include/full-lib-test.c
	gcc -Wall -Wextra -pedantic -std=c99 -o lib.exe include/full-lib-test.c include/data-structures.c

.PHONY: clean

clean:
	rm list.exe
	rm stack.exe
	rm queue.exe