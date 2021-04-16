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
  switch (cmd.code)
  {
  case PUSH:
    stack_push(stack, cmd.args[0]);
    break;
  case POP:
    stack_pop(stack);
    break;
  case ADD:
  {
    int b = stack_pop(stack);
    int a = stack_pop(stack);

    stack_push(stack, a + b);
  }
  break;
  case SUB:
  {
    int b = stack_pop(stack);
    int a = stack_pop(stack);

    stack_push(stack, a - b);
  }
  break;
  case MUL:
  {
    int b = stack_pop(stack);
    int a = stack_pop(stack);

    stack_push(stack, a * b);
  }
  break;
  case DIV:
  {
    int b = stack_pop(stack);
    int a = stack_pop(stack);

    stack_push(stack, a / b);
  }
  break;
  case MOD:
  {
    int b = stack_pop(stack);
    int a = stack_pop(stack);

    stack_push(stack, a % b);
  }
  break;
  case NONE:
    break;
  default:
    return -1;
  }

  return 0;
}