CC = gcc -Wall -Werror -Wextra

build: graph.c functions.o stack.o
	$(CC) graph.c functions.o stack.o

functions.o: functions.c
	$(CC) -c functions.c -o functions.o

stack.o: stack.c
	$(CC) -c stack.c -o stack.o

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