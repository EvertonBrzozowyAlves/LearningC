#include <stdio.h>

int main()
{
    //this is a comment
    printf("********************************\n");
    printf("* Welcome to the guessing game *\n");
    printf("********************************\n");

    int secretNumber = 42;

    // printf("The secret number is %d, keep it secret!\n", secretNumber);

    int guessNumber;

    printf("Guess a number: \n");
    scanf("%d", &guessNumber);
    printf("Your thinking on number %d. Let's see... \n", guessNumber);
}