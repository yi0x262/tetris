#include"tetris.h"
#include"collision_tetris.h"
#include"drop_tetris.h"
#include"spawn_tetris.h"
#include"print_tetris.h"
#include"gameover_tetris.h"
#include"remove_line.h"


int drop_tetro(TETRIS* data)
{
  int lines = 0;
  if(data->game_over)return lines;
  if(!move_tetro(data,WIDTH,0))
  {
    //move line
    appear_tetro(data,fixed);
    lines = remove_line(data->figure,data->color);
    data->score += lines*lines;
    if(!spawn_tetris(data))
    {
      game_over(data);
    }
  }
  return lines;
}
