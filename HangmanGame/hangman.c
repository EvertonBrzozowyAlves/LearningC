#include <stdio.h>
#include <string.h>

void welcomeMessage()
{
    printf("*************************************\n");
    printf("*           HANGMAN GAME            *\n");
    printf("*************************************\n");
}

void getNewLetter(char guesses[26], int *tries)
{
    char letter;
    scanf(" %c", &letter);
    guesses[*tries] = letter;
    *tries++;
}

int main()
{
    char secretWord[20];
    sprintf(secretWord, "WATERMELON");

    // secretWord[10] = '\0';
    // printf("%s\n", secretWord);

    welcomeMessage();

    int guessed = 0;
    int hanged = 0;

    char guesses[26];
    int tries = 0;

    do
    {
        for (int i = 0; i < strlen(secretWord); i++)
        {
            int found = 0;
            for (int j = 0; j < tries; j++)
            {
                if (guesses[j] == secretWord[i])
                {
                    found = 1;
                    break;
                }
            }
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

        printf("Guess a letter:\n");
        getNewLetter(guesses, &tries);

    } while (!guessed && !hanged);
}