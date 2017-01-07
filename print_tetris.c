#include"tetris.h"
#include<stdio.h>

void appear_tetro(TETRIS* data,const char c)
{
  char** fgr = data->figure;
  char** clr = data->color;
  fgr += data->point;
  clr += data->point;
  const int* map;
  map = tetris_map[data->type][data->rotate];
  int i;
  for(i=0;i<4;++i)
  {
    fgr += *(map);
    clr += *(map++);
    **fgr = c;
    **clr = (char)(0x31+data->type);
  }
}
void appear_tetris(TETRIS data[],const char c)
{
  int i;
  for(i=0;i<PLAYER;++i)
  {
    if(data[i].game_over)continue;
    appear_tetro(&data[i],c);
  }
}

void print_state(TETRIS data[])
{
  const int num = 6;
  static char c[20];
  sprintf(c,"%%%ds:%%%dd   ",num,WIDTH-num-1);

  int i;
  printf("\x1b[39m");
  for(i=0;i<PLAYER;++i)
  {
    printf(c,"score",data[i].score);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf(c,"type",data[i].type);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf(c,"rotate",data[i].rotate);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf(c,"point",data[i].point);
  }
  printf("\n");
  for(i=0;i<PLAYER;++i)
  {
    printf(c,"over",data[i].game_over);
  }
  printf("\n");
}

void print_field(TETRIS data[])
{
  static char c[20];
  sprintf(c,"%%.%ds   ",WIDTH*6);

  printf("\x1b[0;0H");//move 0,0

  appear_tetris(data,moving);

  //field
  int d,i;
  for(d = 0;d < DEPTH;++d)
  {
    for(i=0;i<PLAYER;++i)
    {
      printf(c,&data[i].field[6*WIDTH*d]);
    }
    printf("\n");
  }

  appear_tetris(data,empty);

  print_state(data);
}
