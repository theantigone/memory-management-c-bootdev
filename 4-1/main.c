#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "color.h"

MunitResult test_color_enum1(const MunitParameter params[], void* data) {
  assert_int(RED, ==, 0);
  assert_int(GREEN, ==, 1);
  assert_int(BLUE, ==, 2);
	return MUNIT_OK;
};

MunitResult test_color_enum2(const MunitParameter params[], void* data) {
  assert_int(RED, !=, 4);
  assert_int(GREEN, !=, 2);
  assert_int(BLUE, !=, 0);
	return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    { "/are_defined", test_color_enum1},
    { "/are_defined_correctly", test_color_enum2},
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {
	"colors",
	tests,
};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
