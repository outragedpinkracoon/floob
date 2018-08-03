#include "isogram.h"
#include "string_utils.h"
#include <ctype.h>
#include <stdio.h>

bool is_isogram(const char phrase[])
{
  if (empty_or_single(phrase))
    return true;

  int size = get_size(phrase);
  char seen[size];

  int next = 0;

  for(int i = 0; i < size; i++)
  {
    char current_char = phrase[i];

    if(non_letter(current_char))
    {
      continue;
    }

    if(is_upper(current_char))
    {
      current_char = tolower(phrase[i]);
    }

    if(contains(seen, current_char))
    {
      return false;
    }
    else
    {
      seen[next] = current_char;
      next++;
    }
  }

  return true;
}
