.PHONY: all clean test s21_matrix.a gcov_report clang

GCC = gcc -Wall -Werror -Wextra -std=c11 -g

OS := $(shell uname -s)

ifeq ($(OS), Linux)
	LIB = -lcheck -lrt -lpthread -lsubunit -lm
	LEAK = valgrind --tool=memcheck --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
	TO = ./tmp 2>
	LEAK_REPORT = -B 1 -A 3 "ERROR SUMMARY"
	OPEN = xdg-open
endif

ifeq ($(OS), Darwin)
	LIB = -lcheck
	LEAK = leaks -atExit --
	TO =
	LEAK_REPORT = -A 3 "leaks Report Version"
	OPEN = open
endif

all: clean clang gcov_report

s21_matrix.a:
	@$(GCC) -c functions/s21_*.c common_functions/*.c
	@ar rcs s21_matrix.a *.o
	@ranlib s21_matrix.a
	@rm -rf *.o

test : clean s21_matrix.a
	@$(GCC) tests/*.c s21_matrix.a $(LIB) -o s21_test
	@./s21_test
	@-$(LEAK) ./s21_test > $(TO) ./leak.txt
	@-grep $(LEAK_REPORT) ./leak.txt

gcov_report : clean s21_matrix.a
	@$(GCC) functions/s21_*.c tests/*.c s21_matrix.a --coverage $(LIB) -o s21_test
	@./s21_test
	@-$(LEAK) ./s21_test > $(TO) ./leak.txt
	@-grep $(LEAK_REPORT) ./leak.txt
	@mkdir ./report 
	@mv *.g* ./report
	@lcov -c -q -d ./report -o ./report/coverage.info
	@genhtml -q ./report/coverage.info -o ./report
	@$(OPEN) report/index.html

clang: clean
	@cp ../materials/linters/.clang-format ./.clang-format
	clang-format -style=Google -n ./functions/*.c
	clang-format -style=Google -n ./common_functions/*.c
	clang-format -style=Google -n ./tests/*.c ./tests/*.h
	clang-format -style=Google -n ./*.h
	@rm .clang-format

clean :
	@rm -rf *.o *.a s21_matrix.a s21_test *.gcda *.gcno coverage.info ./report tmp leak.txt
