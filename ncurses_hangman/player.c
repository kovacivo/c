#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "guessedword.h"
#include "game.h"
#include "player.h"
/********************************************************
 * CreatePlayer - Creates player with his name
 *
 * Parameters: none
 *
 * Returns
 *
 * pointer to struct Player
 *
 * ********************************************************/

Player *CreatePlayer()
{
    Player *p = (Player *) malloc(sizeof(Player));
    p->turns = MAX_TURNS;
    //printf("Put your name here: ");
    mvprintw(2,5,"Tell me your name: ");
    refresh();
    //scanf("%s", p->name);
    scanw("%s", p->name);

    return p;
}

/********************************************************
 * PlayerEnterSomeTurn - player enters some letter
 *
 * Parameters: Player
 *
 * Returns
 *
 * nothing; only changes the player's letter
 *
 * ********************************************************/
void PlayerEnterSomeLetter(Player *p)
{
    //printf("Your turn: ");
    mvprintw(4,5,"Your turn: ");
    refresh();
    p->letter = (char)getchar();
    while(!(isalpha(p->letter)))
        p->letter = (char)getchar();


    //change to upper case
    p->letter = toupper(p->letter);
    //printf("\n");
}
