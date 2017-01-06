#include"tetris.h"

#include<stdlib.h>
int main(){
  init_tetris();

  int t;
  for(t=0;t<11;++t)
  {
    print_tetris();
  }
  return 0;
}
