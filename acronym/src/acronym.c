#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *p;

void save(int currentChar) {
  *p = toupper(currentChar);
  ++p;
}

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int phraseLen = strlen(phrase);

  if (phraseLen == 0) return NULL;

  p = calloc(0, phraseLen + 1);
  char *pStart = p;

  bool saveNext = false;

  for (int i = 0; i < phraseLen; i++) {
    char currentChar = phrase[i];

    if (i == 0) {
      save(currentChar);
      continue;
    }

    if (saveNext == true) {
      saveNext = false;

      save(currentChar);
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNext = true;
    }
  }
  *p = '\0';
  return pStart;
}
