#include <stdio.h>
#include <string.h>
#include "functions.h"

//global variables
char secretWord[20];
char guesses[26];
int tries = 0;
const int CHANCES = 5;

void printWelcomeMessage()
{
    printf("*************************************\n");
    printf("*           HANGMAN GAME            *\n");
    printf("*************************************\n");
}

void getNewLetter()
{
    char letter;
    scanf(" %c", &letter);
    guesses[tries] = letter;
    tries++;
}

int isLetterAlreadyTried(char letter)
{
    int found = 0;
    for (int i = 0; i < tries; i++)
    {
        if (guesses[i] == letter)
        {
            found = 1;
            break;
        }
    }
    return found;
}

void drawGallows()
{
    for (int i = 0; i < strlen(secretWord); i++)
    {
        int found = isLetterAlreadyTried(secretWord[i]);
        if (found)
        {
            printf("%c ", secretWord[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void chooseSecretWord()
{
    FILE *f;
    f = fopen("words.txt", "r");

    int wordsQuantity;
    fscanf(f, "%d", wordsQuantity); //read the first thing in file

    srand(time(0));
    int random = rand() % wordsQuantity;

    for (int i = 0; i < random; i++)
    {
        //TODO: follow
    }

    fclose(f);
}

int hanged()
{
    int errors = 0;
    for (int i = 0; i < tries; i++)
    {
        int exists = 0;
        for (int j = 0; j < strlen(secretWord); j++)
        {
            if (guesses[i] == secretWord[j])
            {
                exists = 1;
                break;
            }
        }
        if (!exists)
        {
            errors++;
        }
    }
    return errors >= CHANCES;
}

int guessed()
{
    for (int i = 0; i < strlen(secretWord); i++)
    {
        if (!isLetterAlreadyTried(secretWord[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    chooseSecretWord();
    printWelcomeMessage();

    do
    {
        drawGallows();
        printf("Guess a letter:\n");
        getNewLetter();

    } while (!guessed() && !hanged());
}