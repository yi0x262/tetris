#include"tetris.h"
#include<stdio.h>

void appear_tetro(TETRIS data[],const char c)
{
  int i,j,p;
  const int* map;
  for(i=0;i<PLAYER;++i)
  {
    p = (data[i]).point;
    map = tetris_map[data[i].type][data[i].rotate];
    for(j=0;j<4;++j)
    {
      p += map[j];
      *data[i].color[p] = (char)(0x31+data[i].type);
      *data[i].figure[p] = c;
    }
  }
}

void print_field(TETRIS data[])
{
  printf("\x1b[0;0H");//move 0,0

  appear_tetro(data,moving);

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

  appear_tetro(data,empty);
}
