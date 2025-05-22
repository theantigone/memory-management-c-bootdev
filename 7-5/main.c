#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#include "../munit/munit.h"

MunitResult test_swap_str(const MunitParameter params[], void* data) {
  char *a = "Hello";
  char *b = "Goodbye";

  swap_strings(&a, &b);

  assert_string_equal(a, "Goodbye");
  assert_string_equal(b, "Hello");
  return MUNIT_OK;
};

MunitResult test_swap_str_long(const MunitParameter params[], void* data) {
  char *a = "terminal.shop";
  char *b = "ssh";

  swap_strings(&a, &b);

  assert_string_equal(a, "ssh");
  assert_string_equal(b, "terminal.shop");
  return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    {"/swap_str", test_swap_str},
    {"/test_swap_str_long", test_swap_str_long},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {"void-pointer", tests};
  return munit_suite_main(&suite, NULL, 0, NULL);
}

