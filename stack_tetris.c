#include"tetris.h"
#include"xorshift.h"
#include"remove_line.h"

void copy_block(TETRIS* data,int start_depth)
{
  int origin,copy;
  for(origin=start_depth,copy=0;origin<DEPTH-1;++origin,++copy)
  {
    copy_line(data->figure+origin*WIDTH,data->figure+copy*WIDTH);
    copy_line(data->color+origin*WIDTH,data->color+copy*WIDTH);
  }
}

void spawn_line(char* f[],char* c[])
{
  //spawn like |#### ######|
  int w,blank;
  blank = xor_random()%(WIDTH-2);
  ++blank;//1<blank<WIDTH-1

  ++f;++c;
  for(w=1;w<WIDTH-1;++w)
  {
    **(c++) = '0';
    **(f++) = (w==blank) ? empty : fixed;
  }
}

void spawn_black(TETRIS* data)
{
  int d;
  for(d=DEPTH-data->stack-1;d<DEPTH-1;++d)
  {
    spawn_line(data->figure+d*WIDTH,data->color+d*WIDTH);
  }
}

void stack_tetris(TETRIS* data)
{
  copy_block(data,data->stack);
  spawn_black(data);
  data->stack = 0;
}
