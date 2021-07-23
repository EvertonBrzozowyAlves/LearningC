#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

int gameIsFinished();
void moveHero(char direction);
int isValidDirection(char direction);
int getNextPhantomPosition(int currentX, int currentY, int *destinyX, int *destinyY);
