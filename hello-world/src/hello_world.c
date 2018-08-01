#include "hello_world.h"

#define HELLO_WORLD "Hello, World!"

const char *hello(void)
{
  return HELLO_WORLD;
}

const char *helloAgain(void)
{
  const char *text = "Hello again!";

  return text;
}
