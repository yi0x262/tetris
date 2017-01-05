#include<stdlib.h>
#include"tetris.h"
#include"init_tetris.h"
#include"print_tetris.h"

const char empty = ' ';
const char moving = '@';
const char fixed = '#';

static TETRIS tetris[PLAYER];
int draw_flag;

#include<stdio.h>
void init_tetris(void)
{
  printf("\x1b[2J");//clr
  int i;
  for(i=0;i<PLAYER;++i)
  {
    init_data(&tetris[i]);
  }
  draw_flag = 1;
}

void print_tetris(void)
{
  print_field(tetris);
}
