#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "hangman.h"

//global variables
char secretWord[WORD_LENGTH];
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
    int errors = getErrorsCount();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", errors >= 1 ? '(' : ' ', errors >= 1 ? '_' : ' ', errors >= 1 ? ')' : ' ');
    printf(" |      %c%c%c \n", errors >= 3 ? '\\' : ' ', errors >= 2 ? '|' : ' ', errors >= 3 ? '/' : ' ');
    printf(" |       %c    \n", errors >= 4 ? '|' : ' ');
    printf(" |      %c %c  \n", errors >= 5 ? '/' : ' ', errors >= 5 ? '\\' : ' ');
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

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
    if (f == 0)
    {
        printf("Error while starting the game.\n\n");
        exit(1);
    }

    int wordsQuantity;
    fscanf(f, "%d", &wordsQuantity); //read the first thing in file

    srand(time(0));
    int random = rand() % wordsQuantity;

    for (int i = 0; i < random; i++)
    {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
}

int getErrorsCount()
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
    return errors;
}

int hanged()
{
    return getErrorsCount() >= CHANCES;
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

void askToAddNewWord()
{
    printf("Do you want to add a new word to the game? (Y/N) ");

    char response;
    scanf(" %c", &response);

    if (response == 'Y')
    {
        printf("What's the word? ");

        char newWord[WORD_LENGTH];
        scanf("%s", newWord);

        FILE *f;
        f = fopen("words.txt", "r+"); //read and write

        if (f == 0)
        {
            printf("Error while starting the game.\n\n");
            exit(1);
        }
        int quantity;
        fscanf(f, "%d", &quantity);
        quantity++;

        fseek(f, 0, SEEK_SET); //set the reader to the beginning of the file
        fprintf(f, "%d", quantity);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", newWord);

        fclose(f);
    }
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

    if (guessed())
    {
        printf("Congratulations!! You've beat the game!\n");
    }
    else
    {
        printf("That's sad, you loose!! Try again!\n");
    }

    askToAddNewWord();
}