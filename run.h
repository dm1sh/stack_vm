#ifndef RUN_H
#define RUN_H

#include "./stack.h"
#include "./command.h"
#include "./utils.h"

#ifdef IO_OPERATIONS
#include <stdio.h>
#endif

int run(command_t **buff, stack_t *stack);
int exec(command_t cmd, stack_t *stack);

#endif