#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>

#include "exercise.h"
#include "../munit/munit.h"

MunitResult test_formats_int1(const MunitParameter params[], void* data) {
  char buffer[100];
  snek_object_t i = new_integer(5);
  format_object(i, buffer);

  assert_string_equal("int:5", buffer);
	return MUNIT_OK;
};

MunitResult test_formats_string1(const MunitParameter params[], void* data) {
  char buffer[100];
  snek_object_t s = new_string("Hello!");
  format_object(s, buffer);

  assert_string_equal("string:Hello!", buffer);
	return MUNIT_OK;
};

MunitResult test_formats_int2(const MunitParameter params[], void* data) {
  char buffer[100];
  snek_object_t i = new_integer(2014);
  format_object(i, buffer);

  assert_string_equal("int:2014", buffer);
	return MUNIT_OK;
};

MunitResult test_formats_string2(const MunitParameter params[], void* data) {
  char buffer[100];
  snek_object_t s = new_string("nvim btw");
  format_object(s, buffer);

  assert_string_equal("string:nvim btw", buffer);
	return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    {"/integer", test_formats_int2},
    {"/string", test_formats_string2},
    {"/integer_nvim", test_formats_int1},
    {"/string_nvim", test_formats_string1},
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {"format", tests};

  return munit_suite_main(&suite, NULL, 0, NULL);
}

