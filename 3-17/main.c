#include "../munit/munit.h"
#include "exercise.h"
#include <string.h>

// Test function for assigning an employee to a department
static MunitResult
test_assign_employee1(const MunitParameter params[], void* data) {
    employee_t emp = create_employee(2, "CEO Dax");
    department_t dept = create_department("C Suite");
    assign_employee(&emp, &dept);
    munit_assert_string_equal(emp.department->name, "C Suite");
    return MUNIT_OK;
}

// Test function for assigning a manager to a department
static MunitResult
test_assign_manager1(const MunitParameter params[], void* data) {
    employee_t manager = create_employee(3, "Influencer Prime");
    department_t dept = create_department("Marketing");
    assign_manager(&dept, &manager);
    munit_assert_string_equal(dept.manager->name, "Influencer Prime");
    return MUNIT_OK;
}

// Test function for another employee assignment
static MunitResult
test_assign_employee2(const MunitParameter params[], void* data) {
    employee_t emp = create_employee(4, "Vegan Intern Adam");
    department_t dept = create_department("Marketing");
    assign_employee(&emp, &dept);
    munit_assert_string_equal(emp.department->name, "Marketing");
    return MUNIT_OK;
}

// Test function for another manager assignment with ID check
static MunitResult
test_assign_manager2(const MunitParameter params[], void* data) {
    employee_t manager = create_employee(5, "CDO David");
    department_t dept = create_department("C Suite");
    assign_manager(&dept, &manager);
    munit_assert_string_equal(dept.manager->name, "CDO David");
    munit_assert_int(manager.id, ==, 5);
    return MUNIT_OK;
}

int main() {
    // Array of test cases
    MunitTest tests[] = {
        { "/test_assign_employee1", test_assign_employee1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_assign_manager1", test_assign_manager1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_assign_employee2", test_assign_employee2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_assign_manager2", test_assign_manager2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Terminator
    };

    // Test suite definition
    MunitSuite suite = {
        "/employee_department_tests", // Prefix for test names
        tests,                       // Array of tests
        NULL,                        // No subsuites
        1,                           // Number of iterations
        MUNIT_SUITE_OPTION_NONE      // Suite options
    };

    // Run the test suite
    return munit_suite_main(&suite, NULL, 0, NULL);
}
