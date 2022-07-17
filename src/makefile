CC = gcc -Wall -Werror -Wextra

build: graph.c stack.o data_input.o parsing_supplement.o
	$(CC) graph.c  stack.o data_input.o parsing_supplement.o

test: test.c
	$(CC) test.c

functions.o: functions.c
	$(CC) -c functions.c -o functions.o

stack.o: stack.c
	$(CC) -c stack.c -o stack.o

data_input.o: data_input.c
	$(CC) -c data_input.c -o data_input.o

parsing_supplement.o: parsing_supplement.c
	$(CC) -c parsing_supplement.c -o parsing_supplement.o

checks:
	make cpplint
	make cppcheck

cpplint: 
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leaks:
	leaks -atExit -- ../build/./polish_notation

remove_cpplint: CPPLINT.cfg
	rm CPPLINT.cfg