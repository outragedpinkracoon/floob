#include "isogram.h"
#include "string_utils.h"
#include <stdio.h>
#include <strings.h>

bool is_isogram(const char phrase[])
{
  if (empty_or_single(phrase))
    return true;

  int length = strlen(phrase);
  char seen[length];
  int next = 0;

  for (int i = 0; i < length; i++)
  {
    char current_char = phrase[i];
    if (contains(seen, current_char))
    {
      return false;
    }
    else
    {
      seen[next] = current_char;
    }
    next++;
  }

  return true;
}
