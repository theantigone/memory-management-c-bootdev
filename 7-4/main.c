#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#include "../munit/munit.h"

MunitResult test_swap_ints(const MunitParameter params[], void* data) {
  int a = 5;
  int b = 6;

  swap_ints(&a, &b);

  assert_int(a, ==, 6);
  assert_int(b, ==, 5);
  return MUNIT_OK;
};

MunitResult test_swap_ints_same(const MunitParameter params[], void* data) {
  int a = 5;

  swap_ints(&a, &a);

  assert_int(a, ==, 5);
  return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    {"/swap_ints", test_swap_ints},
    {"/swap_ints_same", test_swap_ints_same},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {"void-pointer", tests};
  return munit_suite_main(&suite, NULL, 0, NULL);
}

