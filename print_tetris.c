#include"tetris.h"
#include<stdio.h>

void print_field(TETRIS data[])
{
  //printf("\x1b[2J");//clr
  printf("\x1b[0;0H");//move 0,0
  //field
  int d,i;
  for(d = 0;d < DEPTH;++d)
  {
    printf("\x1b[39m");
    for(i=0;i<PLAYER;++i)
    {
      printf("|%.60s\x1b[39m|\t",&data[i].field[6*WIDTH*d]);
    }
    printf("\n");
  }
  //score
  printf("\x1b[39m");
  for(i=0;i<PLAYER;++i)
  {
    printf("score:%6d\t",data[i].score);
  }
  printf("\n");
}
