CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: s21_grep

s21_grep: findMaxMy.o flagChecker.o grepPrint.o printCLFunc.o printNFunc.o s21_grep.o
	$(CC) $(CFLAGS) $^ -o $@

findMaxMy.o: findMaxMy.c
	$(CC) $(CFLAGS) -c $< -o $@

flagChecker.o: flagChecker.c
	$(CC) $(CFLAGS) -c $< -o $@

grepPrint.o: grepPrint.c
	$(CC) $(CFLAGS) -c $< -o $@

printCLFunc.o: printCLFunc.c
	$(CC) $(CFLAGS) -c $< -o $@

printNFunc.o: printNFunc.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o s21_grep
