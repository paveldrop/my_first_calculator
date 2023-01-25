SOURCE = *.c
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
	rm -rf *.o  ./calc 

# dvi:

# dist:

# tests: install

gcov_report: tests
	gcovr .
	gcovr --html-details -o report.html
	open ./report.html


