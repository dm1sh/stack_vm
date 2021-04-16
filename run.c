#include "./run.h"

int run(command_t *buff, stack_t stack)
{
  int pos = 0;
  int res = 0;

  while (buff[pos] != NULL)
  {
    res = exec(buff[pos], stack);
  }

  return res;
}

int exec(command_t cmd, stack_t stack)
{
  switch (cmd)
  {
  case NONE:
    break;
  default:
    return -1;
  }

  return 0;
}