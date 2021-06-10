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

    printf("Guess a number:");
    scanf("%d", &guessNumber);
    printf("Your thinking on number %d. Let's see... \n", guessNumber);

    int guessed = (guessNumber == secretNumber); //0 => false, 1 => true

    if (guessed)
    {
        printf("You got it right! Congratulations. You won the game!!\n");
        printf("Play again, you're a good player!!\n");
    }
    else
    {
        int guessIsHigherThanSecretNumber = guessNumber > secretNumber;
        if (guessIsHigherThanSecretNumber)
        {
            printf("Your guess is higher than the secret number!\n");
        }
        else
        {
            printf("Your guess is lower than the secret number!\n");
        }
    }
}