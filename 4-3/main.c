#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "http.h"

MunitResult test_switch_enum(const MunitParameter params[], void* data) {
  assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request");
  assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized");
  assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not Found");
  assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!");
  assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR), "500 Internal Server Error");
	return MUNIT_OK;
};

MunitResult test_switch_enum_default(const MunitParameter params[], void* data) {
  assert_string_equal(http_to_str((HttpErrorCode)999), "Unknown HTTP status code");
	return MUNIT_OK;
};

int main() {
  MunitTest tests[] = {
    {"/switch_enum", test_switch_enum},
    {"/switch_enum_default", test_switch_enum_default},
{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
  };

  MunitSuite suite = {
	"http",
	tests,
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
