#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

int get_size(const char *input);
bool empty_or_single(const char *input);
bool contains(const char *input, int search);

#endif
