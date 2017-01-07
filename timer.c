#include<stdio.h>
#include<unistd.h>

int main()
{
  printf("start\n");
  usleep(100);
  printf("end\n");

  char c[100];
  sprintf(c,"%%.%ds",100);
  printf("%s\n",c);
  sprintf(c,c,"test");
  printf("%s\n",c);
  return 0;
}
