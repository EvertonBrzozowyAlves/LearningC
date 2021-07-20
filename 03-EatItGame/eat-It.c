#include <stdio.h>
#include <stdlib.h>
#include "eat-it.h"
#include "map.h"

MAP map;
POSITION heroPosition;

int gameIsFinished()
{
    return 0; //TODO: finish this function
}

void move(char direction)
{
    map.matrix[heroPosition.x][heroPosition.y] = '.';

    switch (direction)
    {
    case 'a':
        map.matrix[heroPosition.x][heroPosition.y - 1] = '@';
        heroPosition.y--;
        break;
    case 'w':
        map.matrix[heroPosition.x - 1][heroPosition.y] = '@';
        heroPosition.x--;
        break;
    case 's':
        map.matrix[heroPosition.x + 1][heroPosition.y] = '@';
        heroPosition.x++;
        break;
    case 'd':
        map.matrix[heroPosition.x][heroPosition.y + 1] = '@';
        heroPosition.y++;
        break;
    }
}

int main(void)
{
    readMap(&map);
    findHeroPositionOnMap(&map, &heroPosition, '@');
    do
    {
        printMap(&map);

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!gameIsFinished());

    freeMapMemory(&map);
}