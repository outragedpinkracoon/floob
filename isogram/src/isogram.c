#include "isogram.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
  int max = strlen(phrase);

  if (max < 2) {
    return true;
  }

  int counts[CHAR_MAX] = {0};

  for (int i = 0; i < max; i++) {
    int letter = phrase[i];

    if (!isalpha(letter)) {
      continue;
    }

    if (isupper(letter)) {
      letter = tolower(letter);
    }

    int count = counts[letter];

    if (count == 0) {
      counts[letter] = 1;
    } else {
      return false;
    }
  }
  return true;
}
