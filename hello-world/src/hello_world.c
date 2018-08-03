#include "hello_world.h"

#define HELLO_WORLD "Hello, World!"

const char *hello(void)
{
  return HELLO_WORLD;
}

const char *text = "Hello again!";

const char *helloAgain(void)
{
  text = "Hello Dan"; //how to make the pointer And the data constant (just the data is right now)
  // check cpp reference site
  return text;
}
