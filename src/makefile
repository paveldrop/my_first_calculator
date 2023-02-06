SOURCE = *.c
SOURCE_TEST = parser.c rpn.c stack_func.c validator.c calculate.c ./tests/test.c credit_calc.c
OBJ = *.o
CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -lcheck -lgcov -coverage

all: clean calc

calc:
	gcc $(CFLAGS) $(SOURCE) -o calc -lm
	./calc

# install:

# uninstall:

clean:
	rm -rf *.o ./calc *.gcno *.gcda ./test *.dSYM

# dvi:

# dist:

test:
	$(CC) $(GCOVFLAGS) $(SOURCE_TEST) -g -c
	$(CC) $(GCOVFLAGS) $(OBJ) -o test -lm
	./test

gcov_report: test
	gcovr .
	gcovr --html-details -o report.html && mv *.html *.css ./report_gcov
	open ./report_gcov/report.html


