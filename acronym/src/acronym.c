#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL || strlen(phrase) == 0) {
    return NULL;
  }

  int phraseLength = strlen(phrase);

  char acronymChars[10] = {0};
  bool saveNextChar = false;
  int nextIndex = 0;

  for (int i = 0; i < phraseLength; i++) {
    char currentChar = phrase[i];

    if (i == 0) {
      acronymChars[nextIndex] = toupper(currentChar);
      nextIndex++;
      continue;
    }

    if (saveNextChar == true) {
      acronymChars[nextIndex] = toupper(currentChar);
      nextIndex++;
      saveNextChar = false;
      continue;
    }

    if (isblank(currentChar) || currentChar == '-') {
      saveNextChar = true;
    }
  }

  char *str = malloc(5);
  strcpy(str, acronymChars);

  return str;
}

