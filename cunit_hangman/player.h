/**
 * @file player.h
 * @author Ivo
 * @date 10 Mar 2016
 * @brief File containing player definition.
 *
 */

#ifndef H_PLAYER
#define H_PLAYER

#define MAX_PLAYERNAME_LEN 20
#define MAX_TURNS 6

typedef struct {
    char name[MAX_PLAYERNAME_LEN];
    int turns;
    char letter;
} Player;

Player* CreatePlayer();
void PlayerEnterSomeLetter(Player *p);

#endif
