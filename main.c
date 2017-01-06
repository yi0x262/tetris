#include"tetris.h"

#include<unistd.h>
int main(){
  init_tetris();

  int t;
  t = 0;
  print_tetris();
  while(1)
  {
    if(input_tetris(0))print_tetris();
    usleep(1000);
    t += 1;
    if(t > 100)
    {
      drop_tetris();
      print_tetris();
      t = 0;
    }
  }
  return 0;
}
