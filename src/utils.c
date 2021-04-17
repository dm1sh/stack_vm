#include "./utils.h"

int str_len(char str[])
{
  int pos = 0;

  while (str[pos] != '\0')
    pos++;

  return pos;
}

int str_eq(char a[], char b[])
{
  int i = 0;
  while (a[i] != '\0' && b[i] != '\0')
  {
    if (a[i] != b[i])
      return 0;

    i++;
  }

  if (a[i] == '\0' && b[i] == '\0')
    return 1;
  else
    return 0;
}

int read_line(FILE *file, char *buff)
{
  int pos = -1;
  char ch;

  while ((ch = getc(file)), ch != EOF && ch != '\n')
  {
    if (pos == -1)
      pos = 0;

    buff[pos] = ch;
    pos++;
  }

  buff[pos] = '\0';

  return pos;
}