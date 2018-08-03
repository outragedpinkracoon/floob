#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

int get_size(const char *input);
bool empty_or_single(const char *input);
bool contains(const char *input, int search);
bool is_lower(const char input);
bool non_letter(const char input);
bool is_upper(const char input);

#endif
