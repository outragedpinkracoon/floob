#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int size = strlen(phrase);
  if (size == 0) return NULL;

  //acronym will never be bigger than size of phrase
  char *p = malloc((size + 1) * sizeof(char));
  //remember this for reallocation later
  char* p_start = p;

  //always save the first character
  *p++ = toupper(*phrase);

  while(*phrase != '\0'){
    char current = *phrase;
    char previous = *(phrase-1);

    if(previous == ' ' || previous == '-')
    {
      *p++ = toupper(current);
    }

    phrase++;
  }
  *p = '\0';

  //resize the return value to save memory
  size_t desired_size = ((p - p_start) + 1) * sizeof(char);
  return realloc(p_start, desired_size);
}
