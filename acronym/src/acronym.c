#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int phraseLen = strlen(phrase);

  if (phraseLen == 0) return NULL;

  char *p = malloc((phraseLen + 1) * sizeof(char));
  char *pStart = p;

  bool saveNext = false;

  for (int i = 0; i < phraseLen; i++) {
    char currentChar = phrase[i];

    if (i == 0 || saveNext == true) {
      saveNext = false;

      *p++ = toupper(currentChar);
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNext = true;
    }
  }
  *p = '\0';
  return pStart;
}
