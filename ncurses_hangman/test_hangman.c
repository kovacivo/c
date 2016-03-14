#include <CUnit/CUnit.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"
#include "game.h"
#include "guessedword.h"

/*
 * List of tests:
 *  -> GuessedWord:
 *      - guessed word is not empty - testGuessedWordNotEmpty
 *  -> Player:
 *      - player name is not empty - testPlayerNameNotEmpty
 *      - player has some turns - testPlayerHasSomeTurns
 *      - player entered some letter - testPlayerEnteredSomeLetter
 *  -> Game:
 *      - check if player can turn - testPlayerCanTurn
 *      - check if guess was correct - testGuessCorrect
 *      - check if guessed word is displayed properly - testShowLetterLocation
 *      - check if game can evaluate properly exit conditions and exit - testGameExit
*/

static Guessedword *guessedword;
static Player *p;
static Game *g;

// Suite GuessedWord
int init_suite_GuessedWord(void)  {
    guessedword = CreateGuessedWord();
    return 0;
}

int clean_suite_GuessedWord(void) {
    free(guessedword);
    return 0;
}

// test_GuessedWordNotEmpty
// guessed word is not empty
void test_GuessedWordNotEmpty(void)
{
//	char *guessed_word;
//    guessed_word = CreateGuessedWord();
  CU_ASSERT_TRUE(strlen(guessedword->guessedword) > 0);
}

// Suite Player
int init_suite_Player(void)  {
    printf("Creating player in Player Suite...\n");
    p = CreatePlayer();
    return 0;
}

int clean_suite_Player(void) {
    free(p);
    return 0;
}

// test_PlayerNameNotEmpty
// player name is not empty
void test_PlayerNameNotEmpty(void)
{
    CU_ASSERT_TRUE(strlen(p->name) > 0);
}

// player has some turns
void test_PlayerHasSomeTurns(void)
{
    CU_ASSERT_TRUE(p->turns > 0);
}

// player entered some turn
void test_PlayerEnteredSomeLetter(void)
{
    PlayerEnterSomeLetter(p);
    CU_ASSERT_TRUE(isalpha(p->letter));
}

// player can turn
void test_PlayerCanTurn(void)
{
    CU_ASSERT_TRUE(PlayerCanTurn(p));
}

// Suite Game
int init_suite_Game(void)  {
    g = CreateGame();
    //g->guessedword->guessedword = "INTERNET";
    printf("In Init Game the guessed word was set to %s\n", g->guessedword->guessedword);
    return 0;
}

int clean_suite_Game(void) {
    free(g);
    return 0;
}

// game tests player's guess
void test_GuessCorrect(void)
{
    PlayerEnterSomeLetter(g->player);
    printf("In GuessCorrect the player\'s letter was %c\n",g->player->letter);
    CU_ASSERT_TRUE(GuessCorrect(g->player->letter, g->guessedword->guessedword, g));
}

// game shows revealed word
void test_ShowLetterLocation(void)
{
    UpdateRevealedWord(g->player->letter, g->guessedword->revealedword, g->guessedword->guessedword, strlen(g->guessedword->guessedword));
    //char *tmp = "...E..E.";
    printf("In ShowRevealedWord the guessedword is %s\n", g->guessedword->guessedword);
    printf("In ShowRevealedWord the revealedword is %s\n", g->guessedword->revealedword);
    //g->guessedword->guessedword = "INTERNET";
    //CU_ASSERT_TRUE(!strcmp(g->guessedword->revealedword,tmp));
    CU_ASSERT_TRUE(!strcmp(g->guessedword->revealedword,g->guessedword->guessedword));
}

// game can exit properly under given conditions
void test_GameExit(void)
{
    g->player->turns = 1;
    g->guessedword->revealedword = "INTERNET";
    CU_ASSERT_TRUE(GameExit(g));
}

// testing begins here
int main (void)
{
   CU_pSuite pSuite = NULL;

   /* Initialize CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* Add GuessedWord suite to registry */
   pSuite = CU_add_suite("Guessed_Word_Suite", init_suite_GuessedWord, clean_suite_GuessedWord);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Guessed word length greater than zero\"", test_GuessedWordNotEmpty))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* Add Player suite to registry */
   pSuite = CU_add_suite("Player_Suite", init_suite_Player, clean_suite_Player);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Player name length greater than zero\"", test_PlayerNameNotEmpty))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Player has some turns\"", test_PlayerHasSomeTurns))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Player entered some letter\"", test_PlayerEnteredSomeLetter))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Player can turn\"", test_PlayerCanTurn))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* Add Game suite to registry */
   pSuite = CU_add_suite("Game_Suite", init_suite_Game, clean_suite_Game);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Player guess was correct\"", test_GuessCorrect))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Show revealed updated word\"", test_ShowLetterLocation))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add test to suite */
   if (NULL == CU_add_test(pSuite, "\"Show game can exit\"", test_GameExit))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run tests using Basic interface */
   CU_basic_set_mode("CU_BRM_VERBOSE");
   CU_basic_run_tests();

   /* Run tests in interactive Console mode */
   //CU_console_run_tests();
   /* Run tests using the Automated interface */
   //CU_automated_run_tests();

    /* Run tests in interactive Console mode */
   //CU_console_run_tests();

   /* Run tests in interactive Curses mode */
   //CU_curses_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
