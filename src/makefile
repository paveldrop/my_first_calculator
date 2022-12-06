SOURCE = 
OBJ = *.o
CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -lcheck -lgcov -coverage

all: clean s21_matrix.a test gcov_report

install:

uninstall:

clean:
	# rm -rf *.o ./test ./s21_matrix.a ./*.gc* ./report*

dvi:

dist:

tests: install

gcov_report: tests
	gcovr .
	gcovr --html-details -o report.html
	open ./report.html


