CC = gcc -Wall -Werror -Wextra
TARGET = ../build

all: graph.c input_and_parse.o RPN.o calculation.o stack_and_struct.a parsing_supplement.o output_supplement.o output.o
	$(CC) graph.c input_and_parse.o RPN.o calculation.o stack_and_struct.a parsing_supplement.o output_supplement.o output.o -o $(TARGET)/graph

run: $(TARGET)/graph
	./$(TARGET)/graph

test: test.c
	$(CC) test.c

output.o: output.c
	$(CC) -c output.c -o output.o

output_supplement.o: output_supplement.c
	$(CC) -c output_supplement.c -o output_supplement.o

RPN.o: RPN.c
	$(CC) -c RPN.c -o RPN.o

calculation.o: calculation.c
	$(CC) -c calculation.c -o calculation.o

stack_and_struct.o: stack_and_struct.c
	$(CC) -c stack_and_struct.c -o stack_and_struct.o

stack_and_struct.a: stack_and_struct.o
	ar rc stack_and_struct.a stack_and_struct.o
	ranlib stack_and_struct.a

input_and_parse.o: input_and_parse.c
	$(CC) -c input_and_parse.c -o input_and_parse.o

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

add_cpplint: ../materials/linters/CPPLINT.cfg
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg

clean:
	rm *.o
	rm *.a