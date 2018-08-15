#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *abbreviate(const char *phrase) {
  if(phrase == NULL)
    return NULL;
  int max = strlen(phrase);

  char stored[5] = { 0 };
  bool saveNext = false;
  int nextIndex = 0;

  for(int i = 0; i < max; i++)
  {
    char current_char = phrase[i];
    //store the first letter and upcase it
    if(i == 0) {
      stored[nextIndex] = toupper(current_char);
      nextIndex++;
      continue;
    }

    if(saveNext == true) {
      stored[nextIndex] = toupper(current_char);
      nextIndex++;
      saveNext = false;
      continue;
    }

    if(isblank(current_char)) {
      saveNext = true;
    }
  }

  char * str = malloc(5);
  strcpy(str, stored);

  return str;
}

// Portable Network Graphics -> PNG
// start looping
// when you see a space, panic
// Store the first letter
