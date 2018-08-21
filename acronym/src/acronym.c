#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int size = strlen(phrase);
  if (size == 0) return NULL;

  char *p = malloc((size + 1) * sizeof(char));
  char *p_start = p;

  const char *phrase_start = phrase;

  while(*phrase != '\0'){
    char current = *phrase;
    char previous = *(phrase-1);

    if (phrase == phrase_start) {
      *p++ = toupper(current);
    }
    else if(previous == ' ' || previous == '-')
    {
      *p++ = toupper(current);
    }

    phrase++;
  }
  *p = '\0';
  return p_start;
}
