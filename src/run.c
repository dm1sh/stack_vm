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
    pos++;
  }

  return res;
}

int exec(command_t cmd, stack_t *stack)
{
  int *res = NULL;

  switch (cmd.code)
  {
  /**
   * Doesn't do anything
   */
  case NONE:
    break;
  /**
   * Pushes value to stack
   */
  case PUSH:
  {
    stack_push(stack, cmd.arg_v[0], res);

    if (res != NULL)
      return *res;
  }
  break;
  /**
   * Removes from stack top
   */
  case POP:
  {
    stack_pop(stack, res);

    if (res != NULL)
      return *res;
  }
  break;
  /**
   * Removes two top values in stack and pushes their sum
   */
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
  /**
   * Removes two top values in stack and pushes substraction of them
   */
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
  /**
   * Removes two top values in stack and pushes multiplication of them
   */
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
  /**
   * Removes two top values in stack and pushes integer part of division
   */
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
  /**
   * Removes two top values in stack and pushes modulo
   */
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
#ifdef IO_OPERATIONS
  /**
   * Inputs string with C I/O operators
   */
  case IN:
  {
    char input[512];
    scanf("%s", input);
    int size = str_len(input);

    for (int pos = size; size >= 0; size--)
    {
      stack_push(stack, input[pos], res);
      if (res != NULL)
        return *res;
    }
  }
  break;
  /**
   * Outputs string with C I/O operators
   */
  case OUT:
  {
    char ch = stack_pop(stack, res);
    if (res != NULL)
      return *res;

    while (ch != '\0')
    {
      putchar(ch);
      ch = stack_pop(stack, res);
      if (res != NULL)
        return *res;
    }
  }
  break;
#endif
  default:
    return 1;
  }

  return 0;
}