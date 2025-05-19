#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "exercise.h"
#include "../munit/munit.h"

MunitResult test_allocate(const MunitParameter params[], void* data) {
  int *pointer = NULL;
  allocate_int(&pointer, 10);

  assert_ptr_not_null(pointer);
  assert_int(*pointer, ==, 10);

  free(pointer);
  return MUNIT_OK;
};

MunitResult test_does_not_overwrite(const MunitParameter params[], void* data) {
  int value = 5;
  int *pointer = &value;

  allocate_int(&pointer, 20);

  assert_int(value, ==, 5);

  assert_ptr_not_null(pointer);
  assert_int(*pointer, ==, 20);

  free(pointer);
  return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    {"/create", test_allocate},
    {"/overwrite", test_does_not_overwrite},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };
  MunitSuite suite = {"allocate_list", tests};

  return munit_suite_main(&suite, NULL, 0, NULL);
}

