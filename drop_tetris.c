#include"tetris.h"
#include"collision_tetris.h"
#include"drop_tetris.h"
#include"spawn_tetris.h"
#include"print_tetris.h"

void drop_tetro(TETRIS* data)
{
  if(!move_tetro(data,WIDTH,0))
  {
    //move line
    appear_tetro(data,fixed);
    spawn_tetris(data);
  }
}
