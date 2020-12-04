/** finalfuncts.h
* ===========================================================
* Name: Trinity Abdulkhalik, 12/3/2020
* Section: T1A
* Project: Hangman
* Purpose: Display understanding of overarching course concepts
* ===========================================================
*/
#ifndef FINALFUNCTS_H
#define FINALFUNCTS_H


void intializeGame(char* wordRead);
int getNumLines();
int updateWord(char* word, char* blanks, char characterInput);
void drawHangman(int incorrectGuess);
void checkWinner(int guessLeft, char* wordChoice, char* blankPhrase, char characterCollect);
int endGame();
//These are the function prototypes.
#endif //FINALFUNCTS_H