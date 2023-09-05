CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

EXCLUDE_FILES = s21_test.c
SOURCES = $(wildcard *.c)
TEST_SOURCES = $(filter-out $(EXCLUDE_FILES), $(SOURCES))
OBJECTS = $(TEST_SOURCES:.c=.o)

tt: 
	@clear
	@gcc ../main.c s21_decimal.a -o ../tt -lm
	@./../tt

s21_decimal.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib s21_decimal.a
	rm -rf *.o

test: 
	@gcc $(CFLAGS) $(SOURCES) -lm -o test -lcheck -lsubunit -lgcov
	@./test

gcov_report:
	@gcc $(CFLAGS) -fprofile-arcs -ftest-coverage $(SOURCES) -lm -o test -lcheck -lsubunit -lgcov
	mkdir -p gcov_report
	./test
	gcovr -r . --html --html-details -o gcov_report/coverage.html
	rm -rf $(OBJECTS) s21_decimal.a test *.gc* test_gcov/*.gc*

clean:
	clear
	@rm -rf *.o *.a *.gc* tt git my gcov_report

all: s21_decimal.a

cpp:
	@cppcheck —enable=all —suppress=missingIncludeSystem *.c

clang:
	@clang-format -n *.c *.h

valgrind:
	@valgrind ./test
