#include "./run.h"

int run(command_t **buff, stack_t *stack)
{
  int pos = 0;
  int res = 0;

  while (buff[pos] != NULL)
  {
    res = exec(*(buff[pos]), stack);
    if (res)
      break;
  }

  return res;
}

int exec(command_t cmd, stack_t *stack)
{
  int *res;

  switch (cmd.code)
  {
  case NONE:
    break;
  case PUSH:
  {
    stack_push(stack, cmd.args[0], res);

    if (res != NULL)
      return *res;
  }
  break;
  case POP:
  {
    stack_pop(stack, res);

    if (res != NULL)
      return *res;
  }
  break;
  case ADD:
  {
    int b = stack_pop(stack, res);
    int a = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    stack_push(stack, a + b, res);
    if (res != NULL)
      return *res;
  }
  break;
  case SUB:
  {
    int b = stack_pop(stack, res);
    int a = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    stack_push(stack, a - b, res);
    if (res != NULL)
      return *res;
  }
  break;
  case MUL:
  {
    int b = stack_pop(stack, res);
    int a = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    stack_push(stack, a * b, res);
    if (res != NULL)
      return *res;
  }
  break;
  case DIV:
  {
    int b = stack_pop(stack, res);
    int a = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    stack_push(stack, a / b, res);
    if (res != NULL)
      return *res;
  }
  break;
  case MOD:
  {
    int b = stack_pop(stack, res);
    int a = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    stack_push(stack, a % b, res);
    if (res != NULL)
      return *res;
  }
  break;
  default:
    return -1;
  }

  return 0;
}