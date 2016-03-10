#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "player.h"
#include "guessedword.h"
/********************************************************
 * CreateGuessedWord - Picks randomly guessed_word from file with words
 *
 * Parameters: none
 *
 * Returns
 *
 * pointer to array of char - to some word
 *
 * ********************************************************/
Guessedword* CreateGuessedWord()
{
    // open file with words
    FILE* word_file = fopen(GUESSED_WORDS_FILE, "r");
    if (word_file == NULL) {
        fprintf(stderr, "File %s could not be open!!!\n", GUESSED_WORDS_FILE);
        exit(1);
    }

    // picks randomly some number
    time_t t;
    // Intializes random number generator
    srand((unsigned) time(&t));
    int rand_number = rand() % NUMBER_OF_WORDS;
    #if defined(DEBUG)
        printf("random number was %d\n", rand_number);
    #endif

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;

    line = (char *) malloc(sizeof(char) * MAX_WORD_LEN);
    while ((read = getline(&line, &len, word_file)) != -1) {
        if (line_number == rand_number)
            break;
        #if defined(DEBUG)
            printf("%s", line);
        #endif
        line_number++;
    }

    #if defined(DEBUG)
        printf("Picked word was: %s", line);
    #endif

    fclose(word_file);

    Guessedword *g = (Guessedword *) malloc(sizeof(Guessedword));

    #ifdef DEBUG
        printf("In CreateGuessedWord func line len is: %d\n", strlen(line));
    #endif

    g->guessedword = (char *) malloc(sizeof(char) * strlen(line));
    strcpy(g->guessedword, line);

    #ifdef DEBUG
        printf("In CreateGuessedWord func guessedword len after copying is: %d\n", strlen(g->guessedword));
    #endif

    g->revealedword = (char *) malloc(sizeof(char) * strlen(line));
    strcpy(g->revealedword, line);

    g->guessedword[strlen(g->guessedword)] = '\0';
    g->revealedword[strlen(g->guessedword)] = '\0';

    //convert guessed word to upper case letters
    int i = 0;
    for(i = 0; i < strlen(g->guessedword) - 1;i++) {
        #ifdef DEBUG
            printf("toupper...%c\n", toupper(g->guessedword[i]));
        #endif
        if(isalpha(g->guessedword[i]))
            g->guessedword[i] = toupper(g->guessedword[i]);
    }

    for(i = 0; i < strlen(g->guessedword) - 1;i++)
        g->revealedword[i] = '.';
    g->revealedword[strlen(g->guessedword)] = '\0';

    #ifdef DEBUG
        printf("In CreateGuessedWord func guessedword len is: %d\n", strlen(g->guessedword));
        printf("In CreateGuessedWord func revealedword len is: %d\n", strlen(g->revealedword));
    #endif

	return g;
};
