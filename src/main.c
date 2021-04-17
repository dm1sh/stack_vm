#include "./run.h"
#include "./stack.h"
#include "./compile.h"
#include "./read_bin.h"

#ifdef IO_OPERATIONS
#include <stdio.h>

void print_help()
{
  printf("*HELP*\n");
}
#endif

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
#ifdef IO_OPERATIONS
    fprintf(stderr, "Illegal input: command must be specified\n");
    print_help();
#endif
    return 2;
  }
  if (strcmp(argv[1], "build") == 0)
  {
    if (argc == 3)
      compile(argv[2], "out.bin");
    else if (argc == 4)
      compile(argv[2], argv[3]);
    else
    {
#ifdef IO_OPERATIONS
      fprintf(stderr, "Illegal input for build:\n");
      print_help();
#endif
      return 2;
    }
  }
  else if (strcmp(argv[1], "run") == 0)
  {
    stack_t *stack;

    int *res = NULL;

    if (argc == 4)
      stack = stack_new(atoi(argv[3]), res);
    else if (argc == 3)
      stack = stack_new(1024, res);
    else
    {
#ifdef IO_OPERATIONS
      fprintf(stderr, "Illegal input for run:\n");
      print_help();
#endif
      return 2;
    }

    if (res != NULL && *res == -1)
    {
#ifdef IO_OPERATIONS
      fprintf(stderr, "Stack creation error: check memory usage.\n");
      print_help();
#endif
      return 1;
    }

    command_t **commands = read_bin_file(argv[2], res);
    if (commands == NULL)
      return 1;

    return run(commands, stack);
  }
  else
  {
#ifdef IO_OPERATIONS
    fprintf(stderr, "Illegal input: no such command\n");
    print_help();
#endif
    return 2;
  }
}
