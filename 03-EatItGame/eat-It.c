#include <stdio.h>
#include <stdlib.h>
#include "eat-it.h"

char **map;
int rows;
int columns;

void readMap()
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (f == 0)
    {
        printf("Error while starting the game.\n\n");
        exit(1);
    }

    fscanf(f, "%d %d", &rows, &columns);

    allocateMap();

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map[i]);
    }
    fclose(f);
}

void allocateMap()
{
    map = malloc(sizeof(char *) * rows); //dynamic allocation
    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(sizeof(char) * (columns) + 1);
    }
}

void printMap()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }
}

void freeMapMemory()
{
    for (int i = 0; i < rows; i++) //freeing the memory allocated
    {
        free(map[i]);
    }
    free(map);
}

int gameIsFinished()
{
    return 0; //TODO: finish this function
}

void move(char direction)
{
    int x, y;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
    case 'a':
        map[x][y - 1] = '@';
        break;
    case 'w':
        map[x - 1][y] = '@';
        break;
    case 's':
        map[x + 1][y] = '@';
        break;
    case 'd':
        map[x][y + 1] = '@';
        break;
    }

    map[x][y] = '.';
}

int main(void)
{
    readMap();

    do
    {
        printMap();

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!gameIsFinished());

    freeMapMemory();
}