#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define BOMB 'b'

int gameIsFinished();
void moveHero(char direction);
int isValidDirection(char direction);
int getNextPhantomPosition(int currentX, int currentY, int *destinyX, int *destinyY);
void explodePill(int x, int y, int times);
void chooseDirectionToExplodePill();
