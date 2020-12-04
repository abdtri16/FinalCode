/** finalfuncts.c
* ===========================================================
* Name: Trinity Abdulkhalik, 12/3/2020
* Section:T1A
* Project: Hangman
* Purpose: Display understanding of overarching course concepts
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

void intializeGame(char* wordRead){//This function opens the file, scans for a word in accordance with the randomly generated index.
    int index = 0;
    FILE* inFile = fopen("dictionary.txt", "r");
        
    if(inFile == NULL){
        printf("Error creating data file: %s.\n", strerror(errno));
        exit(1);
    }
    index = rand() % getNumLines();//This randomly generates the index.
    
    for(int i =0; i <= index; i++){
        fscanf(inFile, " %s ", wordRead);
    }

    fclose(inFile);
    wordRead = (char *) realloc(wordRead, strlen(wordRead));//This reallocates the appropriate amount of memory after the word is selected.
}

int getNumLines(){//This generates the number of lines in the .txt file that feeds into the calculation for the randomized index.
    int numLines = 0;
    char temp[50];
    FILE* inFile = fopen("dictionary.txt", "r");
    while(!feof(inFile)){
        fscanf(inFile, " %s ", temp);
        numLines++;
    }
    return numLines;
}

int updateWord(char* word, char* blanks, char characterInput){//This function replaces the appropriate blank with the appropriate letter.
    int wordLength = strlen(word);
    int correctlyGuessed;
    int guessLeft = 6;
    for (int i = 0; i < wordLength; i++){//This iterates through the word to check if a letter matches at a certain space.
        if (characterInput == word [i]){
            blanks[i] = characterInput;//This statement causes the letter input to replace the appropriate blank if there is a matching letter.
            correctlyGuessed ++;
        }
        else{
            guessLeft--;//This decreases the amount of guesses left and leads into the amount of limbs no the hangman pole are drawn.
        }
       
    }
    return correctlyGuessed;
    return guessLeft;

}

void drawHangman(int incorrectGuess){//This draws the hangman in accordance with the number of guesses left for the user.

    char* hangman[7][100]={ // This is a 2D array. There is one to specify the platform and another one for the string of characters.

                     "  |=====|\n"
                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "  |     |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|     |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     " |      |\n"
                     "       ===\n",

                     "   |=====|\n"
                     "   O     |\n"
                     "  -|-    |\n"
                     "  | |    |\n"
                     "       ===\n"

    };
switch (incorrectGuess){//This switch case prints the appropriate hangman structure for the attempts left.
        case 7:
            printf("\n\n%s\n", hangman[0][0]);
            break;
        case 6:
            printf("\n\n%s\n", hangman[1][0]);
            break;
        case 5:
            printf("\n\n%s\n", hangman[2][0]);
            break;
        case 4:
            printf("\n\n%s\n", hangman[3][0]);
            break;
        case 3:
            printf("\n\n%s\n", hangman[4][0]);
            break;
        case 2:
            printf("\n\n%s\n", hangman[5][0]);
            break;
        case 1:
            printf("\n\n%s\n", hangman[6][0]);
            break;
    }
}

void checkWinner(int guessLeft, char* wordChoice, char* blankPhrase, char characterCollect){//This function checks whether the hangman is complete or if the blanks are correctly filled.
    int i = rand() % getNumLines();
    if (guessLeft > 0){//This is supposed to update the word and hangman structure in accordance with the guesses left for the user as long as the guesses are at a value greater than zero.
            updateWord(wordChoice, blankPhrase, characterCollect);
            drawHangman(guessLeft);
            printf("Winner! Would you like to play again?\n");//This is the victory message.
        }
        else{//This else statement draws the hangman fully with all body parts if the guesses are at 0 and the word has not been filled appropriately.
            drawHangman(1);
            printf("Unfortunately, you lost. The correct word was %s, Would you like to play again?\n", wordChoice[i]);//This is a losing message.
        }
}

int endGame(){//This function asks the player if they wish to replay and scans for a value. If the player wishes to replay, this function resets the game by calling the main function which calls the intiailized functions.
    char val = 'a';
    printf("Replay?")?
    scanf("%d", val);
    if (val == 1){
        return main();
    }
    return 0;
}