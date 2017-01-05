#include<stdio.h>
#include<stdlib.h>

#include<string.h>

char* colorprint(const int i){
  char* c;
  sprintf(c,"\x1b[3%dm%d",i,i);
  return c;
}

void malloctest(char** test,const int len)
{
  (*test) = malloc(sizeof(char)*len);
}

int main(int argc,char *argv[])
{
  printf("test\n");

  const int len = 10;
  char str[len];
  scanf("%s",str);

  //pointer
  int i;
  char* s = str;
  for(i = 0; i < len; i++)
  {
    //printf("%d",i);
    printf("%c",*(s++));
  }
  printf("\n");

  //argument
  for (i = 0; i < argc; i++)
  {
    printf("%d:%s\n",i,argv[i]);
  }

  //esc sequence
  printf("\x1b[2J");//clr
  printf("clr\n");
  printf("\x1b[0;0H");//move 0,0
  printf("\x1b[31m");//change color red
  printf("red\n");
  printf("\x1b[32m#\x1b[33m3\n");
  char c[100];
  for(i=0;i<10;++i)
  {
    sprintf(c,"%s%s",c,colorprint(i));
    //printf("%s",colorprint(i));
  }
  printf("%s\n",c);
  printf("%d\n",(int)strlen(c));


  //allocate
  char* maltest;
  //maltest=malloc(sizeof(char)*len);
  malloctest(&maltest,len);
  for(i=0;i<len;++i){
    maltest[i] = '@';
  }
  printf("%s\n",maltest);

  return 0;
}
