#include "./compile.h"

int compile(char input_src[], char output_src[])
{
  FILE *input = fopen(input_src, "r");
  FILE *output = fopen(output_src, "wb");
  if (input == NULL)
  {
    fprintf(stderr, "Unable to open input file\n");
    return 1;
  }
  if (output == NULL)
  {
    fprintf(stderr, "Unable to open output file\n");
    return -1;
  }

  int size = -1;
  fwrite(&size, sizeof(int), 1, output);
  size++;

  char buffer[512];
  int len = 0;

  while ((len = read_line(input, buffer)), len >= 0)
  {
    if (len == 0)
      continue;

    char *pch = strtok(buffer, " ");

    cmd_desc_t *description = get_desc(pch);
    if (description == NULL)
    {
      fprintf(stderr, "No such command %s\n", pch);
      return 1;
    }

    fwrite(&description->command, sizeof(int), 1, output);

    for (int i = 0; i < description->argc; i++)
    {
      pch = strtok(NULL, " ");
      if (pch == NULL)
      {
        fprintf(stderr, "Not enough arguments for %s\n", description->name);
        return 1;
      }

      int arg = atoi(pch);

      if (arg == 0 && pch[0] != '0')
      {
        fprintf(stderr, "Unsupported argument for %s\n", description->name);
        return 1;
      }

      fwrite(&arg, sizeof(int), 1, output);
    }

    size++;
  }

  fseek(output, 0, SEEK_SET);
  fwrite(&size, sizeof(int), 1, output);

  fclose(input);
  fclose(output);
}