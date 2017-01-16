#include"tetris.h"

int check_line(char* fgr[])
{
  int w;
  for(w=1,++fgr;w<WIDTH-1;++w)
  {
    if(**(fgr++) != fixed)return 0;
  }
  return 1;
}

void copy_line(char* origin[],char* copy[])
{
  int w;
  for(w=1,++origin,++copy;w<WIDTH-1;++w)**(copy++) = **(origin++);
}

void empty_line(char* fgr[])
{
  int w;
  for(w=1,++fgr;w<WIDTH-1;++w)**(fgr++) = empty;
}

int remove_line(char* figure[],char* color[])
{
  int d,count;
  count = 0;//how many remove?
  for(d=DEPTH-1;d>=count;--d)
  {
    if(check_line(figure+d*WIDTH))count += 1;
    if(count)
    {
      copy_line(figure+(d-count)*WIDTH,figure+d*WIDTH);
      copy_line(color+(d-count)*WIDTH,color+d*WIDTH);
    }
  }
  for(d=count-1;d==0;--d)empty_line(figure+d*WIDTH);

  return count;
}
