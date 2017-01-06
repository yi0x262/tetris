#include"tetris.h"
#include<stdio.h>

void appear_tetro(TETRIS* data,const char c)
{
  int j,p;
  const int* map;
  p = (*data).point;
  map = tetris_map[(*data).type][(*data).rotate];
  for(j=0;j<4;++j)
  {
    p += map[j];
    *(*data).color[p] = (char)(0x31+(*data).type);
    *(*data).figure[p] = c;
  }
}
void appear_tetris(TETRIS data[],const char c)
{
  int i;
  for(i=0;i<PLAYER;++i)
  {
    appear_tetro(&data[i],c);
  }
}

void print_state(TETRIS data[])
{
  int i;
  printf("\x1b[39m");
  for(i=0;i<PLAYER;++i)
  {
    printf("score:%6d\t",data[i].score);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf("type:%7d\t",data[i].type);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf("rotate:%5d\t",data[i].rotate);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf("point:%6d\t",data[i].point);
  }
  printf("\n");
}

void print_field(TETRIS data[])
{
  printf("\x1b[0;0H");//move 0,0

  appear_tetris(data,moving);

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

  appear_tetris(data,empty);

  print_state(data);
}
