#include"tetris.h"
#include"collision_tetris.h"
#include"drop_tetris.h"
#include"spawn_tetris.h"
#include"print_tetris.h"
#include"gameover_tetris.h"
#include"remove_line.h"


void drop_tetro(TETRIS* data)
{
  if(data->game_over)return;
  if(!move_tetro(data,WIDTH,0))
  {
    //move line
    appear_tetro(data,fixed);
    data->score += remove_line(data->figure,data->color);
    if(!spawn_tetris(data))
    {
      game_over(data);
    }
  }
}
