CC=gcc
CFLAGS="-g -Wall"
LDFLAGS=
LIBS="-lcunit"

play_hangman: play_hangman.c player.c guessedword.c game.c
	gcc -Wall -g play_hangman.c -o play_hangman player.c guessedword.c game.c

clean:
			rm -f *~ *.o $(objects) test_hangman play_hangman

all: test_hangman

test_hangman: test_hangman.c player.c guessedword.c game.c
	$(CC) $(CLFLAGS) $? $(LDFLAGS) $(LIBS) -o $@

