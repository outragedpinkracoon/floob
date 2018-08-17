#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int phraseLen = strlen(phrase);

  if (phraseLen == 0) return NULL;

  char acronym[max] = {0};

  bool saveNext = false;
  int next = 0;

  for (int i = 0; i < phraseLen; i++) {
    char currentChar = phrase[i];

    if (i == 0) {
      acronym[next] = toupper(currentChar);
      next++;
      continue;
    }

    if (saveNext == true) {
      acronym[next] = toupper(currentChar);
      next++;
      saveNext = false;
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNext = true;
    }
  }

  char *copy = malloc(max);
  strcpy(copy, acronym);

  return copy;
}
