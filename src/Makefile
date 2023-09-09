CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

SOURCES = $(wildcard functions/*.c)
OBJECTS = $(SOURCES:.c=.o)

tt: clean s21_decimal.a
	@clear
	@gcc tests/main.c s21_decimal.a -lm -o temp
	@gcc ../s21_decimal1/src/1.c ../s21_decimal1/src/s21_decimal.a -lm -o temp1
	@./temp1
	@./temp

s21_decimal.a: clean $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib s21_decimal.a
	rm -rf functions/*.o

test: clean
	@gcc $(CFLAGS) $(SOURCES) tests/s21_test.c -lm -o test -lcheck -lsubunit -lgcov
	@./test

gcov_report:
	@gcc $(CFLAGS) -fprofile-arcs -ftest-coverage $(SOURCES) tests/s21_test.c -lm -o test -lcheck -lsubunit -lgcov
	mkdir -p gcov_report
	./test
	gcovr -r . --html --html-details -o gcov_report/coverage.html
	rm -rf $(OBJECTS) s21_decimal.a test *.gc* test_gcov/*.gc*

clean:
	clear
	@rm -rf functions/*.o *.a *.gc* tt git my gcov_report

all: s21_decimal.a

cpp:
	@cppcheck —enable=all —suppress=missingIncludeSystem *.c

clang:
	@clang-format -n *.c *.h

valgrind:
	@valgrind ./test
