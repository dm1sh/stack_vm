#include "./stack.h"

stack_t *stack_new(int size, int *result)
{
  result = NULL;

  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  if (stack == NULL)
  {
    *result = -1;
    return *result;
  }

  stack->mem = (int *)malloc(sizeof(int) * size);
  if (stack->mem == NULL)
  {
    *result = -1;
    return *result;
  }

  stack->size = size;
  stack->cursor = -1;

  return stack;
}

int stack_push(stack_t *stack, int value, int *result)
{
  result = NULL;

  if (stack->cursor > stack->size - 1)
  {
    *result = 1;
    return *result;
  }

  stack->mem[stack->cursor + 1] = value;
  stack->cursor += 1;

  return 0;
}

int stack_pop(stack_t *stack, int *result)
{
  result = NULL;

  if (stack->cursor == -1)
  {
    *result = 1;
    return *result;
  }

  int value = stack->mem[stack->cursor];
  stack->cursor -= 1;

  return value;
}

int stack_get(stack_t *stack, int pos, int *result)
{
  result = NULL;

  if (pos < 0 || pos >= stack->size)
  {
    *result = 1;
    return *result;
  }

  return stack->mem[pos];
}