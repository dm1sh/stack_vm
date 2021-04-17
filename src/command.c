#include "./command.h"

cmd_desc_t cmd_desc[] = {
    {PUSH, 1, "PUSH"},
    {POP, 0, "POP"},
    {ADD, 0, "ADD"},
    {SUB, 0, "SUB"},
    {MUL, 0, "MUL"},
    {DIV, 0, "DIV"},
    {MOD, 0, "MOD"},
#ifdef IO_OPERATIONS
    {IN, 0, "IN"},
    {OUTS, 0, "OUTS"},
    {OUTC, 0, "OUTC"},
#endif
    {NONE, 0, "NONE"}};

command_t *command_new(cmd_code_t type, int args[])
{
  command_t *cmd = (command_t *)malloc(sizeof(command_t));

  cmd->code = type;
  cmd->arg_v = malloc(sizeof(int) * cmd_desc[type].argc);

  for (int i = 0; i < cmd_desc[type].argc; i++)
    cmd->arg_v[i] = args[i];

  return cmd;
}

cmd_desc_t *get_desc(char name[])
{
  for (int i = 0; i < sizeof(cmd_desc) / sizeof(cmd_desc_t); i++)
    if (str_eq(name, cmd_desc[i].name))
      return &cmd_desc[i];

  return NULL;
}