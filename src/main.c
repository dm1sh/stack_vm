#include "./run.h"
#include "./stack.h"
#include "./compile.h"
#include "./read_bin.h"
#include <stdio.h>

void print_help()
{
  printf("*HELP*\n");
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Illegal input: command must be specified\n");
    print_help();

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
      fprintf(stderr, "Illegal input for build:\n");
      print_help();

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
      fprintf(stderr, "Illegal input for run:\n");
      print_help();

      return 2;
    }

    if (res != NULL && *res == -1)
    {
      fprintf(stderr, "Stack creation error: check memory usage.\n");
      print_help();

      return 1;
    }

    command_t **commands = read_bin_file(argv[2], res);
    if (commands == NULL)
    {
      stack_free(stack);
      fprintf(stderr, "Couldn't read file\n");
      return 1;
    }

    int response = run(commands, stack);

    stack_free(stack);
    command_arr_free(commands);
    return response;
  }
  else
  {
    fprintf(stderr, "Illegal input: no such command\n");
    print_help();

    return 2;
  }
}
