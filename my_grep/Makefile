CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: s21_grep

s21_grep: s21_grep.o
	$(CC) $(CFLAGS) $^ -o $@
	rm -f *.o

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	-rm -f s21_grep
