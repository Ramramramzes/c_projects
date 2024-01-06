CC_FLAGS = -Wall -Wextra -Werror -std=c11
ifeq ($(shell uname), Darwin)
#	Команды для MacOS
	CC_FLAGS += -I /usr/local/include
	CHECK_FLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib/ -lcheck -lpthread
	OPEN_HTML = open
else
#	Команды для Linux
	CHECK_FLAGS = -lcheck -lpthread -lrt -lsubunit
	OPEN_HTML = xdg-open
endif

all: clean s21_string.a s21_string test gcov_report

s21_string.a: s21_string.c s21_sprintf.c
	gcc $(CC_FLAGS) -c s21_string.c s21_sprintf.c
	ar rcs s21_string.a s21_string.o s21_sprintf.o
	rm s21_string.o s21_sprintf.o

s21_string: main.c s21_string.c s21_sprintf.c
	gcc $(CC_FLAGS) s21_string.c main.c s21_sprintf.c -o s21_string -L. s21_string.a -lm

test: clean s21_string.c s21_sprintf.c tests/tests_main.c
	gcc $(CC_FLAGS) s21_string.c s21_sprintf.c tests/*.c -o test $(CHECK_FLAGS) -lm -fprofile-arcs -ftest-coverage

gcov_report: clean test
	./test
	lcov -t "gcov_tests" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_HTML) report/index.html

# Подключение библиотеки s21_string.a к файлу: #include "s21_string.h"
# Компиляция с использованием библиотеки s21_string.a: gcc test1.c -o test1 s21_string.a

clean:
	rm -rf ./s21_string gcov_tests report ./test
	rm -f *.o *.gch s21_string.a
	rm -rf *.gcno *.gcda *.info

clang:
	cp ../materials/linters/.clang-format ./   
	clang-format -i *.c *.h tests/*.c tests/*.h

clang_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h tests/*.c tests/*.h

rebuild: clean all
