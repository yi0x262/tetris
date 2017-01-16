#include<stdio.h>
#include<stdlib.h>

#include"tetris.h"
#include"init_tetris.h"
#include"print_tetris.h"
#include"spawn_tetris.h"
#include"collision_tetris.h"
#include"input.h"
#include"drop_tetris.h"
#include"stack_tetris.h"

const char empty = ' ';
const char moving = '@';
const char fixed = '#';

const int tetris_map[TETRO_TYPE][4][4] = {
  {{0,1,1,1},{0,WIDTH,WIDTH,WIDTH},{0,1,1,1},{0,WIDTH,WIDTH,WIDTH}},//I
  {{0,1,WIDTH-2,1},{0,WIDTH,1,WIDTH},{0,1,WIDTH-2,1},{0,WIDTH,1,WIDTH}},//s
  {{0,1,WIDTH-1,1},{0,1,WIDTH-1,1},{0,1,WIDTH-1,1},{0,1,WIDTH-1,1}},//O
  {{0,1,WIDTH,1},{1,WIDTH-1,1,WIDTH-1},{0,1,WIDTH,1},{1,WIDTH-1,1,WIDTH-1}},//z
  {{0,1,1,WIDTH-2},{0,WIDTH,WIDTH,1},{2,WIDTH-2,1,1},{0,1,WIDTH,WIDTH}},//L
  {{0,1,1,WIDTH},{1,WIDTH,WIDTH-1,1},{0,WIDTH,1,1},{0,1,WIDTH-1,WIDTH}},//J
  {{0,1,1,WIDTH-1},{0,WIDTH-1,1,WIDTH},{0,WIDTH-1,1,1},{0,WIDTH,1,WIDTH-1}},//T
};

static TETRIS tetris[PLAYER];
int draw_flag;

void init_tetris(void)
{
  printf("\x1b[2J");//clr
  int i;
  for(i=0;i<PLAYER;++i)
  {
    init_data(&tetris[i]);
    spawn_tetris(&tetris[i]);
  }

  draw_flag = 1;
}

void print_tetris(void)
{
  print_field(tetris);
}

int input_tetris(int id)
{
  switch(getch())
  {
    case '@':
      return 0;
    case 'a':
      move_tetro(&tetris[id],-1,0);
      break;
    case 's':
      move_tetro(&tetris[id],WIDTH,0);
      break;
    case 'd':
      move_tetro(&tetris[id],1,0);
      break;
    case ';':
      move_tetro(&tetris[id],0,1);
      break;
    case ':':
      move_tetro(&tetris[id],0,-1);
      break;
  }
  return 1;
}

void drop_tetris(void)
{
  int i,j,lines;
  for(i=0;i<PLAYER;++i)
  {
    lines = drop_tetro(&tetris[i]);
    for(j=0;j<PLAYER*(lines>0);++j)
    {
      if(i==j)continue;
      tetris[j].stack += lines;
    }
  }
  for(i=0;i<PLAYER;++i)
  {
    stack_tetris(&tetris[i]);
  }
}
