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

  bool saveNext = false;

  while(*phrase != '\0'){
    char current = *phrase;

    if (phrase == phrase_start || saveNext == true) {
      saveNext = false;
      *p++ = toupper(current);
    }
    else if (isblank(current) || current == '-') {
      saveNext = true;
    }
    phrase++;
  }
  *p = '\0';
  return p_start;
}
