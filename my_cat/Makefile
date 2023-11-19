GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c99
PROG = s21_cat

all: clean $(PROG)

$(PROG): s21_cat.c
	$(GCC) $(FLAGS) s21_cat.c -o $(PROG)

clean:
	rm -rf $(PROG)
