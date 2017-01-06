#include"tetris.h"

int collision_check(char* figure[],int point,const int type,const int rotate)
{
  int i;
  const int* map = tetris_map[type][rotate];
  for(i=0;i<4;++i)
  {
    point += map[i];
    if(*(figure[point]) != empty)return 0;//NG
  }
  return 1;//OK
}

int move_check(TETRIS* data,const int move)
{
  return collision_check((*data).figure,(*data).point + move,(*data).type,(*data).rotate);
}

int move_tetro(TETRIS* data,const int move)
{
  int result;
  result = move_check(data,move);
  if(result)(*data).point += move;
  return result;
}
