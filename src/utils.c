#include "./utils.h"

int str_len(char str[])
{
  int pos = 0;

  while (str[pos] != '\0')
    pos++;

  return pos;
}