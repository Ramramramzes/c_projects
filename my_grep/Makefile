GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c99
PROG = s21_grep

all: clean $(PROG)

$(PROG): s21_grep.c
	$(GCC) $(FLAGS) s21_grep.c -o $(PROG)

clean:
	rm -rf $(PROG)
