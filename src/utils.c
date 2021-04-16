#include "./utils.h"

int str_len(char str[])
{
  int pos = 0;

  while (str[pos] != NULL)
    pos++;

  return pos;
}