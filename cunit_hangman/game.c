/**
 * @file game.c
 * @author Ivo
 * @date 10 Mar 2016
 * @brief File containing definition of all game functions
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "player.h"

/**
*
This method will be used to return boolean if player has non-zero number of turns.
*
@param player Player object
@return true or false
*/
int PlayerCanTurn(Player *p)
{
    return(p->turns > 0);
}

/**
*
This method will be used to create Game object.
*
@param none
@return Game object
*/

Game *CreateGame(void)
{
    Game *g = (Game *)malloc(sizeof(Game));
    g->player = CreatePlayer();
    g->guessedword = CreateGuessedWord();

    return g;
}

/**
*
This method will be used to tell if player's guess was correct or wrong.
*
@param letter Letter the player entered
@param *word  Guessed word
@param *g     Game object
@return true or false
*/

int GuessCorrect(char letter, char *word, Game *g)
{
    if (index(word, letter)) {
        return 1;
    }
    else {
        printf("Wrong guess!!!\n");
        g->player->turns--;
        return 0;
    }
}
/**
*
This method will be used to update the revealed word with letters.
*
@param letter Letter the player entered
@param *revealedword  Revealed word
@param *guessedword  Guessed word
@param guessedword_length Length of guessed word
@return true or false
*/

void UpdateRevealedWord(char letter, char *revealedword, const char *guessedword, int guessedword_length)
{
    int i = 0;
    //for (i = 0; i < guessedword_length - 1; i++) {
    for (i = 0; i < guessedword_length; i++) {
        if (letter == guessedword[i])
            revealedword[i] = letter;
    }

}

/**
*
This method will be used to show revealed word to user.
*
@param *g Game object
@return nothing
*/

void ShowRevealedWord(Game *g)
{
    printf("%s\n",g->guessedword->revealedword);
}

/**
*
This method will be used to exit game properly when exit conditions are met.
*
@param *g Game object
@return 1 if player runs out turns
@return 2 if player guessed all the letters - that is he won
@return 0 if player lost
*/

int GameExit(Game *g)
{
    if(g->player->turns == 0) {
        printf("You lost this time.\n");
        printf("The guessed word was: %s\n",g->guessedword->guessedword);
        return 1;
    } else if (!strcmp(g->guessedword->guessedword,g->guessedword->revealedword)) {
        printf("You won!!!\n");
        printf("The guessed word really was: %s\n",g->guessedword->guessedword);
        return 2;
    } else {
        #ifdef DEBUG
            printf("Game is still in progress!!!\n");
        #endif
        return 0;
    }
}

/**
*
This method will be used to display parts of gallow on wrong guess.
*
@param *g Game object
@return nothing
*/

void DisplayGallow(Game *g)
{
    switch (g->player->turns) {

        case(5):
            DisplayGallowLegs();
            break;

        case(4):
            DisplayGallowHands();
            DisplayGallowLegs();
            break;
        case(3):
            DisplayGallowNeck();
            DisplayGallowHands();
            DisplayGallowLegs();
            break;
        case(2):
            DisplayGallowHead();
            DisplayGallowNeck();
            DisplayGallowHands();
            DisplayGallowLegs();
            break;
        case(1):
            DisplayGallowRope();
            DisplayGallowHead();
            DisplayGallowNeck();
            DisplayGallowHands();
            DisplayGallowLegs();
            break;
        default:
            ;
    }
}

void DisplayGallowLegs(void)
{
    printf("\t\t |\n");
    printf("\t\t/\\\n");
}

void DisplayGallowHands(void)
{
    printf("\t\t-.-\n");
}

void DisplayGallowNeck(void)
{
    printf("\t\t |\n");
}

void DisplayGallowHead(void)
{
    printf("\t\t O\n");
}

void DisplayGallowRope(void)
{
    printf("\t\t---\n");
    printf("\t\t | \n");
}
