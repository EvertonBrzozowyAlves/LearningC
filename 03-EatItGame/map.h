struct map
{
    char **matrix;
    int rows;
    int columns;
};
typedef struct map MAP;

struct position
{
    int x;
    int y;
};
typedef struct position POSITION;

void readMap(MAP *map);
void freeMapMemory(MAP *map);
void allocateMap(MAP *map);
void printMap(MAP *map);
void findHeroPositionOnMap(MAP *map, POSITION *position, char characterToSearch);
