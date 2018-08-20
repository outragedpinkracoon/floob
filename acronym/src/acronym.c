#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int phraseLen = strlen(phrase);

  if (phraseLen == 0) return NULL;

  char *p = calloc(0, phraseLen + 1);
  char *pStart = p;

  bool saveNext = false;

  for (int i = 0; i < phraseLen; i++) {
    char currentChar = phrase[i];

    if (i == 0) {
      *p = toupper(currentChar);
      ++p;

      continue;
    }

    if (saveNext == true) {
      *p = toupper(currentChar);
      ++p;

      saveNext = false;
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNext = true;
    }
  }
  *p = '\0';
  return pStart;
}
