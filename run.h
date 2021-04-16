#ifndef RUN_H
#define RUN_H

#include "./stack.h"
#include "./command.h"

int run(command_t *buff, stack_t stack);
int exec(command_t cmd, stack_t stack);

#endif