#define HERO '@'
#define PHANTOM 'F'
#define PILL 'P'
#define EMPTY_SPACE '.'
#define VERTICAL_LIMIT '|'
#define HORIZONTAL_LIMIT '-'

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
int findActorPositionOnMap(MAP *map, POSITION *position, char characterToSearch);
int isValidPosition(MAP *map, int x, int y);
int isEmptyPosition(MAP *map, int x, int y);
void moveOnMap(MAP *map, int originX, int originY, int destinyX, int destinyY);
void copyMap(MAP *destiny, MAP *origin);
int canWalkOnMap(MAP *map, int x, int y);
int isPositionAWall(MAP *map, int x, int y);
int isPositionThisActor(MAP *map, char actor, int x, int y);
