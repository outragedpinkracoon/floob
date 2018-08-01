#include <stddef.h>
#include "vendor/unity.h"
#include "../src/hello_world.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello(void)
{
   TEST_ASSERT_EQUAL_STRING("Hello, World!", hello());
}

void test_hello_again(void)
{
   TEST_ASSERT_EQUAL_STRING("Hello again!", helloAgain());
}

int main(void)
{
   UnityBegin("test/test_hello_world.c");

   RUN_TEST(test_hello);
   RUN_TEST(test_hello_again);

   UnityEnd();

   return 0;
}
