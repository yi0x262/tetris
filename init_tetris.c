#include<stdio.h>//for sprintf
#include<stdlib.h>//for malloc
#include"tetris.h"
#include"init_tetris.h"

void set_field(char* figure[],char* color[],const char c,const char f,const int start,const int step,const int times)
{
  int i;
  color += start;
  figure += start;
  for(i=0;i<times;++i)
  {
    **color = c;
    **figure = f;
    color += step;
    figure += step;
  }
}

void init_field(char field[],char* figure[],char* color[])
{
  //all empty
  int i,end;
  for(i=0,end=WIDTH*DEPTH;i<end;++i)
  {
    sprintf(field,"\x1b[3%dm%c",0,empty);
    field+=6;
  }

  set_field(figure,color,'9','|',0,WIDTH,DEPTH);
  set_field(figure,color,'9','|',WIDTH-1,WIDTH,DEPTH);
  set_field(figure,color,'9','-',WIDTH*(DEPTH-1),1,WIDTH);
}

void init_figure_color(char field[],char* figure[],char* color[])
{
  int i,end;
  for(i=0,end=WIDTH*DEPTH;i<end;++i)
  {
    *(figure++) = (field+5);
    *(color++) = (field+3);
    field += 6;
  }
}

void init_data(TETRIS* data)
{
  //allocate
  data->field = malloc(sizeof(char) * DEPTH*WIDTH * 6);
  data->figure = malloc(sizeof(char*)*DEPTH*WIDTH);
  data->color = malloc(sizeof(char*) *DEPTH*WIDTH);
  //initialize
  data->score = 0;
  data->point = 0;
  data->type = 0;
  data->rotate = 0;
  init_figure_color(data->field,data->figure,data->color);
  init_field(data->field,data->figure,data->color);

  data->game_over = 0;
}
