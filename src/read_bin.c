#include "./read_bin.h"

command_t **read_bin_file(char src[], int *res)
{
  FILE *file = fopen(src, "rb");
  if (file == NULL)
    return NULL;

  int size = -1;
  fread(&size, sizeof(int), 1, file);

  command_t **buffer = malloc(sizeof(command_t *) * (size + 1));
  if (buffer == NULL)
  {
    *res = -1;
    return NULL;
  }

  for (int i = 0; i < size; i++)
  {
    buffer[i] = malloc(sizeof(command_t));

    fread(&buffer[i]->code, sizeof(int), 1, file);

    if (cmd_desc[buffer[i]->code].argc)
    {
      buffer[i]->arg_v = malloc(sizeof(int) * cmd_desc[buffer[i]->code].argc);
      fread(buffer[i]->arg_v, sizeof(int), cmd_desc[buffer[i]->code].argc, file);
    }
  }

  buffer[size] = NULL;

  fclose(file);

  return buffer;
}
