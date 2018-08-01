#include "string_utils.h"
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>

int get_size(const char *input)
{
  const char *i;
  int size = 0;

  for (i = input; *i != '\0'; i++)
  {
    size++;
  }

  return size;
}

bool empty_or_single(const char *input)
{
  int size = get_size(input);
  return size == 0 || size == 1;
}

bool contains(const char *input, int search)
{
  int size = get_size(input);

  for (int i = 0; i < size; i++)
  {
    if (input[i] == search)
      return true;
  }
  return false;
}
