#define PLAYER 8
#define WIDTH 10
#define DEPTH 10

//parameter

const char empty;
const char moving;
const char fixed;

typedef struct tetris_data
{
  int score;
  int point;
  int type;
  char* field;
  char** figure;//charactors in field
  char** color;//chars' color number in field
}TETRIS;

//function
void init_tetris(void);
void print_tetris(void);
