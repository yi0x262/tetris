#define PLAYER 5
#define WIDTH 16
#define DEPTH 24

//parameter

const char empty;
const char moving;
const char fixed;

typedef struct tetris_data
{
  int score;
  int point;
  int type;
  int rotate;
  char* field;
  char** figure;//charactors in field
  char** color;//chars' color number in field
  int stack;

  int game_over;
}TETRIS;

#define TETRO_TYPE 7
extern const int tetris_map[TETRO_TYPE][4][4];

//function
void init_tetris(void);
void print_tetris(void);
int input_tetris(int);
void drop_tetris(void);
