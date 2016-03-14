/**
 *  @file player.h
 *  @author Ivo
 *  @date 10 Mar 2016
 *  @brief File containing guessedword definition.
 *
 */

#ifndef H_GUESSEDWORD
#define H_GUESSEDWORD

#include <string.h>
#define MAX_WORD_LEN 20
#define NUMBER_OF_WORDS 20
#define GUESSED_WORDS_FILE "guessed_words.txt"

typedef struct {
    char *guessedword;
    char *revealedword;
} Guessedword;

//char* CreateGuessedWord();
Guessedword* CreateGuessedWord();

#endif
