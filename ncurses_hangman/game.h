/**
 * @file game.h
 * @author Ivo
 * @date 10 Mar 2016
 * @brief File containing game definition.
 *
 */

#ifndef H_GAME
#define H_GAME
#include "player.h"
#include "guessedword.h"

typedef struct {
    Player *player;
    Guessedword *guessedword;
    Guessedword *revealedword;
} Game;

Game *CreateGame(void);
int PlayerCanTurn(Player *p);
int GuessCorrect(char letter, char *word, Game *g);
void UpdateRevealedWord(char letter, char *revealedword, const char *guessedword, int guessedword_length);
int GameExit(Game *g);
void ShowRevealedWord(Game *g);

void DisplayGallow(Game *g);
void DisplayGallowHead(void);
void DisplayGallowRope(void);
void DisplayGallowNeck(void);
void DisplayGallowLegs(void);
void DisplayGallowHands(void);


#endif
