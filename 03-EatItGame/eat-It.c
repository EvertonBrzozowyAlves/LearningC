#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eat-it.h"
#include "map.h"

MAP map;
POSITION heroPosition;
int heroHasPill;

void chooseDirectionToExplodePill()
{
    if (!heroHasPill)
    {
        return;
    }

    explodePill(heroPosition.x, heroPosition.y, 0, 1, 3);
    explodePill(heroPosition.x, heroPosition.y, 0, -1, 3);
    explodePill(heroPosition.x, heroPosition.y, 1, 0, 3);
    explodePill(heroPosition.x, heroPosition.y, -1, 0, 3);

    heroHasPill = 0;
}

void explodePill(int x, int y, int sumOnX, int sumOnY, int times)
{
    if (times == 0)
    {
        return;
    }

    int newX = x + sumOnX;
    int newY = y + sumOnY;

    if (!isValidPosition(&map, newX, newY))
    {
        return;
    }
    if (isPositionAWall(&map, newX, newY))
    {
        return;
    }

    map.matrix[newX][newY] = EMPTY_SPACE;
    explodePill(newX, newY, sumOnX, sumOnY, times - 1);
}

int getNextPhantomPosition(int currentX, int currentY, int *destinyX, int *destinyY)
{
    int options[4][2] = //4 possible options, 2 numbers per option
        {{currentX - 1, currentY},
         {currentX + 1, currentY},
         {currentX, currentY - 1},
         {currentX, currentY + 1}};

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int position = rand() % 4;
        if (canWalkOnMap(&map, options[position][0], options[position][1]))
        {
            *destinyX = options[position][0];
            *destinyY = options[position][1];
            return 1;
        }
    }
    return 0;
}

void movePhantoms()
{
    MAP copy;
    copyMap(&map, &copy);

    for (int i = 0; i < map.rows; i++)
    {
        for (int j = 0; j < map.columns; j++)
        {
            if (copy.matrix[i][j] == PHANTOM)
            {
                int destinyX, destinyY;
                int foundNextPhantomPosition = getNextPhantomPosition(i, j, &destinyX, &destinyY);

                if (foundNextPhantomPosition)
                {
                    moveOnMap(&map, i, j, destinyX, destinyY);
                }
            }
        }
    }
    freeMapMemory(&copy);
}

int gameIsFinished()
{
    POSITION pos;
    int foundHeroPosition = findActorPositionOnMap(&map, &pos, HERO);
    return !foundHeroPosition;
}

int isValidDirection(char direction)
{
    return direction == UP || direction == LEFT || direction == DOWN || direction == RIGHT;
}

void moveHero(char direction)
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

    if (!canWalkOnMap(&map, nextX, nextY))
    {
        return;
    }

    if (isPositionThisActor(&map, PILL, nextX, nextY))
    {
        heroHasPill = 1;
    }

    moveOnMap(&map, heroPosition.x, heroPosition.y, nextX, nextY);

    heroPosition.x = nextX;
    heroPosition.y = nextY;
}

int main(void)
{
    readMap(&map);
    findActorPositionOnMap(&map, &heroPosition, HERO);
    do
    {
        printMap(&map);

        char command;
        scanf(" %c", &command);
        moveHero(command);

        if (command == BOMB)
        {
            chooseDirectionToExplodePill();
        }

        movePhantoms();

    } while (!gameIsFinished());

    freeMapMemory(&map);
}