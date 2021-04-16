#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack
{
  int size;
  int *mem;
  int cursor;
} stack_t;

stack_t *stack_new(int size, int *result);
int stack_push(stack_t *stack, int value, int *result);
int stack_pop(stack_t *stack, int *result);
int stack_get(stack_t *stack, int pos, int *result);

#endif