#include <ncurses.h>
#include "player.h"
#include "game.h"
#include "guessedword.h"

int main(int argc, char* argv[])
{

    initscr();

    mvprintw(1,5,"Welcome to hangman game!!!\n");
    refresh();
    Game *g = CreateGame();

    #ifdef DEBUG
        printf("Picked word to guess was %s\n", g->guessedword->guessedword);
    #endif

    mvprintw(3,5,"Hi %s!!!\n", g->player->name);
    refresh();

    ShowRevealedWord(g);

    while(1) {
        // game has started
        if(GameExit(g))
            break;

        mvprintw(8,5,"You've got yet %d turns.\n", g->player->turns);
        refresh();
        PlayerEnterSomeLetter(g->player);
        if(GuessCorrect(g->player->letter, g->guessedword->guessedword, g)) {
            UpdateRevealedWord(g->player->letter, g->guessedword->revealedword, g->guessedword->guessedword, strlen(g->guessedword->guessedword));
            ShowRevealedWord(g);
            continue;
        } else
            DisplayGallow(g);
            ShowRevealedWord(g);

    }

    mvprintw(22,5,"Press any key to exit.");
    getch();
    refresh();

    endwin();
    return 0;
}
