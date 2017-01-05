#include<stdio.h>//for sprintf
#include<stdlib.h>//for malloc
#include"tetris.h"
#include"init_tetris.h"

void set_field(char* figure[],char* color[],const char c,const char f,const int start,const int step,const int times)
{
  int i;
  for(i=0;i<times;++i)
  {
    *color[start+i*step] = c;
    *figure[start+i*step] = f;
  }
}

void init_field(char* field[],char* figure[],char* color[])
{
  //all empty
  int i,end;
  for(i=0,end=WIDTH*DEPTH;i<end;++i)
  {
    sprintf(&(*field)[6*i],"\x1b[3%dm%c",0,moving);
  }

  set_field(figure,color,'9','|',0,WIDTH,DEPTH);
  set_field(figure,color,'9','|',WIDTH-1,WIDTH,DEPTH);
  set_field(figure,color,'9','-',WIDTH*(DEPTH-1),1,WIDTH);
}

void init_figure_color(char field[],char** figure[],char** color[])
{
  int i,end;
  for(i=0,end=WIDTH*DEPTH;i<end;++i)
  {
    (*figure)[i] = &field[6*i + 5];
    (*color)[i] = &field[6*i + 3];
  }
}

void init_data(TETRIS* data)
{
  //allocate
  (*data).field = malloc(sizeof(char) * DEPTH*WIDTH * 6);
  (*data).figure = malloc(sizeof(char*)*DEPTH*WIDTH);
  (*data).color = malloc(sizeof(char*) *DEPTH*WIDTH);
  //initialize
  (*data).score = 0;
  (*data).point = 0;
  (*data).type = 0;
  init_figure_color((*data).field,&(*data).figure,&(*data).color);
  init_field(&(*data).field,(*data).figure,(*data).color);
}
