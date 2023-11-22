CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: s21_cat

s21_cat: flagChecker.o printFile.o simplePrint.o s21_cat.o
	$(CC) $(CFLAGS) $^ -o $@

printFile.o: printFile.c
	$(CC) $(CFLAGS) -c $< -o $@

simplePrint.o: simplePrint.c
	$(CC) $(CFLAGS) -c $< -o $@

flagChecker.o: flagChecker.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f *.o s21_cat
	