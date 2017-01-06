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

int move_tetro(TETRIS* data,const int move,const int rotate)
{
  int result,new_point,new_rotate;
  new_point = (*data).point + move;
  new_rotate = ((*data).rotate + rotate)&0x0003;//0<rotate<3
  result = collision_check((*data).figure,new_point,(*data).type,new_rotate);
  if(result){
    (*data).point = new_point;
    (*data).rotate = new_rotate;
  }
  return result;
}
