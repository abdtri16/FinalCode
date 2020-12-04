/** finalmain.c
* ===========================================================
* Name: Trinity Abdulkhalik, 12/3/2020
* Section: T1A
* Project: Hangman
* Purpose: Display understanding of overarching course concepts
* Documentation: C3C LaRosa reviewed my code and aided in debugging 
* =========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finalfuncts.h"

int main(){

	int guessesLeft = 6;//This intializes the guesses allowed to the user.
	char* wordBank = (char*) malloc(50 * sizeof(char*));//This allocates enough memory to fit any words in the dictionary.

	initializeGame(wordBank); //Using the word throughout the program, we need to keep the value in our main function. This is why we pass by refernce.

	while (!endgame()){ //This loop calls all of the functions so that they may be executed.
		drawHangman(guessesLeft);
		updateWord(word, blanks, characterInput);
		checkWinner(guessesLeft, wordChoice, blankPhrase, characterCollect);
	}
	endGame();
	
system("pause");
return 0;
}