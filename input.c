#include "input.h"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

//https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
/*
int main()
{
  while(1){
    if (kbhit())
    {
      printf("put %c\n",getchar());
    }
  }
  return 0;
}
*/
char getch(void)
{
  if(kbhit())
  {
    return getchar();
  }
  return '@';
}
