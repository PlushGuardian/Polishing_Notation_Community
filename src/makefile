CC=gcc -Wall -Werror -Wextra -g -ggdb3
SOURCES= output_supplement.c structures.c testing_structures.c 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=../build/graph

it:
	make build
	valgrind $(EXECUTABLE)
	make clean

build: $(SOURCES) $(EXECUTABLE)

run:
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) -o $@

.cpp.o:
	$(CC)  $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f *.o
	rm -f *.a

# CC = gcc -Wall -Werror -Wextra
# TARGET = ../build
# TARGET_NAME = graph

# build: graph.c input_and_parse.o RPN.o calculation.o stack_and_struct.a parsing_supplement.o output_supplement.o output.o
# 	$(CC) graph.c input_and_parse.o RPN.o calculation.o stack_and_struct.a parsing_supplement.o output_supplement.o output.o -o $(TARGET)/$(TARGET_NAME) -lm

# run: $(TARGET)/$(TARGET_NAME)
# 	./$(TARGET)/$(TARGET_NAME)

# RPN: testing_rpn.c RPN_2.o output_supplement.o
# 	$(CC) -g testing_rpn.c RPN_2.o output_supplement.o -o $(TARGET)/$(TARGET_NAME) -lm

# RPN_2.o: RPN_2.c 
# 	$(CC) -c RPN_2.c -o RPN_2.o 

# gdb: $(TARGET)/$(TARGET_NAME)
# 	gdb -q ./$(TARGET)/$(TARGET_NAME)

# valgrind: $(TARGET)/$(TARGET_NAME)
# 	valgrind --leak-check=full --track-origins=yes ./$(TARGET)/$(TARGET_NAME)

# test: test.c
# 	$(CC) test.c

# output.o: output.c
# 	$(CC) -c output.c -o output.o

# output_supplement.o: output_supplement.c
# 	$(CC) -c output_supplement.c -o output_supplement.o

# RPN.o: RPN.c
# 	$(CC) -c RPN.c -o RPN.o

# calculation.o: calculation.c
# 	$(CC) -c calculation.c -o calculation.o

# stack_and_struct.o: stack_and_struct.c
# 	$(CC) -c stack_and_struct.c -o stack_and_struct.o

# stack_and_struct.a: stack_and_struct.o
# 	ar rc stack_and_struct.a stack_and_struct.o
# 	ranlib stack_and_struct.a

# input_and_parse.o: input_and_parse.c
# 	$(CC) -c input_and_parse.c -o input_and_parse.o

# parsing_supplement.o: parsing_supplement.c
# 	$(CC) -c parsing_supplement.c -o parsing_supplement.o

# checks:
# 	make cpplint
# 	make cppcheck

# cpplint: 
# 	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

# cppcheck:
# 	cppcheck --enable=all --suppress=missingIncludeSystem *.c

# leaks:
# 	valgrind --leak-check=yes $(TARGET)/./$(TARGET_NAME)

# remove_cpplint: CPPLINT.cfg
# 	rm CPPLINT.cfg

# add_cpplint: ../materials/linters/CPPLINT.cfg
# 	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg

