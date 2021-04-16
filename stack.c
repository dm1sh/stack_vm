#include "./stack.h"

stack_t *stack_new(int size)
{
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  if (stack == NULL)
    return -1;

  stack->mem = (int *)malloc(sizeof(int) * size);
  if (stack->mem == NULL)
    return -1;

  stack->size = size;
  stack->cursor = -1;

  return stack;
}

int stack_push(stack_t *stack, int value)
{
  if (stack->cursor > stack->size - 1)
    return 1;

  stack->mem[stack->cursor + 1] = value;
  stack->cursor += 1;

  return 0;
}

int stack_pop(stack_t *stack)
{
  if (stack->cursor == -1)
    return 1;

  int value = stack->mem[stack->cursor];
  stack->cursor -= 1;

  return value;
}

int stack_get(stack_t *stack, int pos)
{
  if (pos < 0 || pos >= stack->size)
    return 1;

  return stack->mem[pos];
}