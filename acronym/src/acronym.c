#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) return NULL;

  int phraseLen = strlen(phrase);

  if (phraseLen == 0) return NULL;

  char *acronym = malloc(phraseLen + 1);

  bool saveNext = false;
  int count = 0;

  for (int i = 0; i < phraseLen; i++) {
    char currentChar = phrase[i];

    if (i == 0) {
      *acronym = toupper(currentChar);
      ++acronym;

      count++;
      continue;
    }

    if (saveNext == true) {
      *acronym = toupper(currentChar);
      ++acronym;

      count++;
      saveNext = false;
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNext = true;
    }
  }
  *acronym = '\0';
  return acronym - count;
}
