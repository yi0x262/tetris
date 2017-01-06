
#include"tetris.h"
#include"xorshift.h"//random()
#include"collision_tetris.h"

int spawn_tetris(TETRIS* data)
{
  (*data).point = (int)WIDTH*0.5;
  (*data).type = xor_random()%TETRO_TYPE;
  (*data).rotate = 0;
  return move_check(data,0);
}
