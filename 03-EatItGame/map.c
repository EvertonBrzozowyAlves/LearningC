#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void findHeroPositionOnMap(MAP *map, POSITION *position, char characterToSearch)
{
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->columns; j++)
        {
            if (map->matrix[i][j] == characterToSearch)
            {
                position->x = i;
                position->y = j;
                break;
            }
        }
    }
}

void freeMapMemory(MAP *map)
{
    for (int i = 0; i < map->rows; i++) // map->rows == *map.rows
    {
        free(map->matrix[i]); //freeing the memory allocated
    }
    free(map->matrix);
}

void readMap(MAP *map)
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (f == 0)
    {
        printf("Error while starting the game.\n\n");
        exit(1);
    }

    fscanf(f, "%d %d", &map->rows, &map->columns);

    allocateMap(map);

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map->matrix[i]);
    }
    fclose(f);
}

void allocateMap(MAP *map)
{
    map->matrix = malloc(sizeof(char *) * map->rows); //dynamic allocation
    for (int i = 0; i < map->rows; i++)
    {
        map->matrix[i] = malloc(sizeof(char) * (map->columns) + 1);
    }
}

void printMap(MAP *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        printf("%s\n", map->matrix[i]);
    }
}

int isValidPosition(MAP *map, int x, int y)
{
    return x >= map->rows && y >= map->columns;
}

int isEmptyPosition(MAP *map, int x, int y)
{
    return map->matrix[x][y] == EMPTY_SPACE;
}

void moveOnMap(MAP *map, int originX, int originY, int destinyX, int destinyY)
{
    char actor = map->matrix[originX][originY];
    map->matrix[destinyX][destinyY] = actor;
    map->matrix[originX][originY] = EMPTY_SPACE;
}