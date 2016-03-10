#include <stdio.h>
#include "player.h"
#include "game.h"
#include "guessedword.h"

int main(int argc, char* argv[])
{

    printf("Welcome to hangman game\n");
    Game *g = CreateGame();

    #ifdef DEBUG
        printf("Picked word to guess was %s\n", g->guessedword->guessedword);
    #endif

    printf("Player name set to %s\n", g->player->name);

    ShowRevealedWord(g);

    while(1) {
        // game has started
        if(GameExit(g))
            break;

        printf("Player number of turns is %d\n", g->player->turns);
        PlayerEnterSomeLetter(g->player);
        if(GuessCorrect(g->player->letter, g->guessedword->guessedword, g)) {
            UpdateRevealedWord(g->player->letter, g->guessedword->revealedword, g->guessedword->guessedword, strlen(g->guessedword->guessedword));
            ShowRevealedWord(g);
            continue;
        } else
            DisplayGallow(g);
            ShowRevealedWord(g);
    }

    return 0;
}
