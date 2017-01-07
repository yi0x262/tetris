#include"tetris.h"

void game_over(TETRIS* data)
{
  data->game_over = 1;

  //char** f = data->figure;
  char** c = data->color;

  int i,end;
  for(i=0,end=WIDTH*DEPTH;i<end;++i)
  {
    //**(f++) = moving;
    **(c++) = '0';
  }
}
