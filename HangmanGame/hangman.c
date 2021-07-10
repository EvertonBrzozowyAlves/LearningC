#include <stdio.h>
#include <string.h>

char secretWord[20];
char guesses[26];
int tries = 0;

void welcomeMessage()
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
    sprintf(secretWord, "WATERMELON");
}

int main()
{
    int guessed = 0;
    int hanged = 0;

    chooseSecretWord();
    welcomeMessage();

    do
    {
        drawGallows();
        printf("Guess a letter:\n");
        getNewLetter();

    } while (!guessed && !hanged);
}