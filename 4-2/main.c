#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "color.h"

static MunitResult test_color_enum1(const MunitParameter params[], void* data) {
  assert_int(RED, ==, 55);
  assert_int(GREEN, ==, 176);
  assert_int(BLUE, ==, 38);
	return MUNIT_OK;
};

static MunitResult test_color_enum2(const MunitParameter params[], void* data) {
  assert_int(RED, !=, 0);
  assert_int(GREEN, !=, 120);
  assert_int(BLUE, !=, 215);
	return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    { "/defined", test_color_enum1},
    { "/defined_vscode", test_color_enum2},
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {
	"colors",
	tests,
};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
