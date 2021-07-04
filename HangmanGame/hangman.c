#include <stdio.h>
#include <string.h>

int main()
{
    char secretWord[20];
    sprintf(secretWord, "WATERMELON");

    // secretWord[10] = '\0';
    // printf("%s\n", secretWord);

    int guessed = 0;
    int hanged = 0;

    char guesses[26];
    int tries = 0;

    do
    {
        for (int i = 0; i < strlen(secretWord); i++)
        {
            printf("_ ");
        }
        printf("\n");

        char letter;
        scanf(" %c", &letter);

        guesses[tries] = letter;

    } while (!guessed && !hanged);
}