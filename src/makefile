SOURCE = *.c
SOURCE_TEST = parser.c rpn.c stack_create.c validator.c calculate.c ./tests/test.c
OBJ = *.o
CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -lcheck -lgcov -coverage

all: clean calc

calc:
	gcc $(CFLAGS) $(SOURCE) -o calc
	./calc

# install:

# uninstall:

clean:
	rm -rf *.o ./calc *.gcno *.gcda ./test *.dSYM

# dvi:

# dist:

test:
	$(CC) $(GCOVFLAGS) $(SOURCE_TEST) -g -c
	$(CC) $(GCOVFLAGS) $(OBJ) -o test
	./test

gcov_report: test
	gcovr .
	gcovr --html-details -o report.html && mv *.html *.css ./report_gcov
	open ./report_gcov/report.html


