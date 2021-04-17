#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>

#include "./utils.h"

enum command_e
{
  PUSH,
  POP,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
#ifdef IO_OPERATIONS
  IN,
  OUT,
#endif
  NONE
};

typedef enum command_e cmd_code_t;

typedef struct
{
  cmd_code_t command;
  int argc;
  char name[10];
} cmd_desc_t;

extern cmd_desc_t cmd_desc[];

typedef struct
{
  cmd_code_t code;
  int *arg_v;
} command_t;

command_t *command_new(cmd_code_t type, int args[]);
cmd_desc_t *get_desc(char name[]);

#endif