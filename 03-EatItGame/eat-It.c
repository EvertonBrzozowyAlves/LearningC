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

int isValidDirection(char direction)
{
    return direction == UP || direction == LEFT || direction == DOWN || direction == RIGHT;
}

void move(char direction)
{
    if (!isValidDirection(direction))
    {
        return; //it's possible to have an if without brackets, for a simple line
    }

    int nextX = heroPosition.x;
    int nextY = heroPosition.y;

    switch (direction)
    {
    case UP:
        nextX--;
        break;
    case LEFT:
        nextY--;
        break;
    case DOWN:
        nextX++;
        break;
    case RIGHT:
        nextY++;
        break;
    }

    if (!isValidPosition(&map, nextX, nextY))
    {
        return;
    }

    if (!isEmptyPosition(&map, nextX, nextY))
    {
        return;
    }

    moveOnMap(&map, heroPosition.x, heroPosition.y, nextX, nextY);
    heroPosition.x = nextX;
    heroPosition.y = nextY;
}

int main(void)
{
    readMap(&map);
    findHeroPositionOnMap(&map, &heroPosition, HERO);
    do
    {
        printMap(&map);

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!gameIsFinished());

    freeMapMemory(&map);
}