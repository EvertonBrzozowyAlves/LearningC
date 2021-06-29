#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define NUMBER_OF_TRIES 3

int main()
{
    //this is a comment
    printf("********************************\n");
    printf("* Welcome to the guessing game *\n");
    printf("********************************\n");

    int seconds = time(0);
    srand(seconds);
    int bigNumber = rand();

    int secretNumber = bigNumber % 100;

    // printf("The secret number is %d, keep it secret!\n", secretNumber);
    // int chances = 3;
    int guessNumber;
    int tries = 1;
    double points = 1000;

    // for (int i = 1; i <= NUMBER_OF_TRIES; i++)

    while (1)
    {
        printf("This is yout try number: %d\n", tries); //%d to print int
        printf("Guess a number: ");
        scanf("%d", &guessNumber);
        printf("Your thinking on number %d. Let's see... \n", guessNumber);

        if (guessNumber < 0)
        {
            printf("Negative numbers are not allowed!\n");
            continue;
        }

        int guessed = (guessNumber == secretNumber); //0 => false, 1 => true
        int greater = guessNumber > secretNumber;

        if (guessed)
        {
            break;
        }
        else if (greater)
        {
            printf("Your guess is higher than the secret number!\n");
        }
        else
        {
            printf("Your guess is lower than the secret number!\n");
        }
        printf("\n");
        tries++;

        double lostPoints = abs(guessNumber - secretNumber) / (double)2; //to make the result a float
        points -= lostPoints;
    }
    printf("Game over!\n");
    if (tries == 1)
    {
        printf("You beat the game in one try! You're awesome!\n");
    }
    else
    {
        printf("You took %d tries to beat the game!\n", tries);
    }
    printf("Final points: %.1f!\n", points); //%f to print floats
}