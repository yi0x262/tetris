#include<stdlib.h>//abs()
#include<stdint.h>//uint32_t
#include"xorshift.h"
//https://ja.wikipedia.org/wiki/Xorshift
uint32_t xorshift(void)
{
  static uint32_t y = 2463534242;
  y = y^(y<<13);y=y^(y>>17);
  return y=y^(y<<5);
}

int xor_random(void)
{
  return abs((int)xorshift());
}
