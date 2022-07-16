CC = gcc -Wall -Werror -Wextra

build: graph.c stack.o data_input.o
	$(CC) graph.c  stack.o data_input.o

functions.o: functions.c
	$(CC) -c functions.c -o functions.o

stack.o: stack.c
	$(CC) -c stack.c -o stack.o

data_input.o: data_input.c
	$(CC) -c data_input.c -o data_input.o

checks:
	make cppLint
	make cppCheck

cppLint: 
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppCheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leaks:
	leaks -atExit -- ../build/./polish_notation

remove_cpplint: CPPLINT.cfg
	rm CPPLINT.cfg