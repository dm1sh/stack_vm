#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack
{
  int size;
  int *mem;
  int cursor;
} stack_t;

stack_t *stack_new(int size);
int stack_push(stack_t *stack, int value);
int stack_pop(stack_t *stack);
int stack_get(stack_t *stack, int pos);

#endif