CC=gcc
CFLAGS="-g -Wall"
LDFLAGS=
LIBS=-lcunit -lncurses

play_hangman: play_hangman.c player.c guessedword.c game.c
	$(CC) $(CLFLAGS) $? $(LDFLAGS) $(LIBS) -o $@

clean:
			rm -f *~ *.o $(objects) test_hangman play_hangman

all: test_hangman play_hangman

test_hangman: test_hangman.c player.c guessedword.c game.c
	$(CC) $(CLFLAGS) $? $(LDFLAGS) $(LIBS) -o $@

