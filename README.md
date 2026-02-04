## Boot.dev Memory Management Free Membership

[Learn Memory Management in C](https://www.boot.dev/courses/learn-memory-management-c)

### How it works:
~~1. Download the [``µnit`` framework](https://github.com/nemequ/munit/)~~
> The µnit framework is already installed in the repository...
> 
> When cloning this repository, if the ``µnit`` repository is empty, run:
```shell
~/bootdev-memory-management/ $ git submodule update --init --recursive
```
> to update the ``µnit`` repository.
> Source: https://github.blog/open-source/git/working-with-submodules/

2. Download the exercise files inside [Boot.dev's Memory Management chapters and lessons](https://www.boot.dev/lessons/44a4421c-cc49-4472-bbad-a14f81f860b4) (exercise.c, exercise.h, main.c, etc.)
3. Edit the ``main.c`` file, which usually contains the ``µnit`` framework, to its default configurations (on [Boot.dev's Memory Management Course](https://www.boot.dev/courses/learn-memory-management-c), it modifies the ``µnit`` framework to its own liking).
> Refer to [µnit's documentation](https://nemequ.github.io/munit/) on how to format the unit test cases to their default configurations.
4. After attempting the exercises, inside their respective chapter & lesson folder, run
```shell
~/bootdev-memory-management/chapter-lesson $ gcc main.c ../munit/munit.c
```
or if you have C files, such as ``exercise.c``, run:
```shell
~/bootdev-memory-management/chapter-lesson $ gcc main.c exercise.c ../munit/munit.c
```
5. Run
```shell
~/bootdev-memory-management/chapter-lesson $ ./a.out
```
or whatever name of the executable you set the output to (e.g. `gcc main.c -o test_program`, then run `./test_program`).

6. As long as you configured your ``main.c`` correctly, either it should fail to compile, it should output `MUNIT_FAIL`, or it should output `MUNIT_ERROR` (I think?).
> If ``main.c`` outputs `MUNIT_SKIP`, you probably don't have `return MUNIT_OK` statements in your test case functions.
7. Voila!

# NEW INSTRUCTIONS FOR NEW CODE

Here is the updated `README.md` content. I have designed this as a **Local Development Guide** section that you can append to your existing README.

It encapsulates all the steps we took: creating the mock library, patching the test suite, and the specific compilation flags needed to make everything work smoothly.

---

### **Local Development Setup**

This repository contains solutions for the [Boot.dev Memory Management in C](https://www.boot.dev/courses/learn-memory-management-c) course.

Because Boot.dev uses a custom testing environment (with specific helper libraries and macros), running these exercises locally requires a few configuration steps. Follow this guide to set up your local environment to be compatible with both legacy and new exercises.

#### **1. Prerequisites**

* **GCC**: Ensure you have `gcc` installed (`sudo apt install gcc` or `brew install gcc`).
* **Munit**: The `munit` testing framework is included as a submodule or folder in this repo.

#### **2. Create the Mock `bootlib.h**`

Boot.dev exercises often include `<bootlib.h>` for memory tracking. Locally, we mock this to satisfy the compiler.

Create a file at `munit/bootlib.h` with the following content:

```c
#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stdbool.h>

// Mock implementation for local running.
// On Boot.dev, this checks if all allocated memory has been freed.
// Locally, we will always return true to allow tests to proceed.
static inline bool boot_all_freed() {
    return true; 
}

#endif

```

#### **3. Patch `munit.h` for Compatibility**

Boot.dev uses shorthand macros (e.g., `munit_case`, `assert_int`) that are not part of the standard munit library. We need to add a compatibility layer.

Open `munit/munit.h` and append the following code to the **very end of the file** (just before the final `#endif`):

```c
/* =============================================================
   Boot.dev Compatibility Layer
   Allows running Boot.dev exercises locally without modification.
   ============================================================= */

// 1. Run types (ignored locally)
#ifndef RUN
#define RUN 0
#endif

#ifndef SUBMIT
#define SUBMIT 1
#endif

// 2. Test Suite Macros
#define munit_case(type, name, ...) \
    static MunitResult name(const MunitParameter params[], void* user_data_or_fixture) { \
        (void)params; \
        (void)user_data_or_fixture; \
        __VA_ARGS__ \
        return MUNIT_OK; \
    }

#define munit_test(name, func) \
    { (char*)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name_str, tests_array) \
    { (char*)name_str, tests_array, NULL, 1, MUNIT_SUITE_OPTION_NONE }

// 3. Assertion Aliases
// Maps Boot.dev's "assert_xyz" to standard "munit_assert_xyz".
// The "...)" and "__VA_ARGS__" logic allows us to ignore the extra 
// error message string that Boot.dev sometimes passes as a last argument.

#define assert_int(a, op, b, ...)         munit_assert_int(a, op, b)
#define assert_string_equal(a, b, ...)    munit_assert_string_equal(a, b)
#define assert_true(expr, ...)            munit_assert_true(expr)
#define assert_false(expr, ...)           munit_assert_false(expr)
#define assert_null(ptr, ...)             munit_assert_null(ptr)
#define assert_not_null(ptr, ...)         munit_assert_not_null(ptr)
#define assert_ptr_not_null(ptr, ...)     munit_assert_not_null(ptr)
#define assert_ptr_equal(a, b, ...)       munit_assert_ptr_equal(a, b)
#define assert_ptr_not_equal(a, b, ...)   munit_assert_ptr_not_equal(a, b)
#define assert_double(a, op, b, ...)      munit_assert_double(a, op, b)

/* =============================================================
   End Boot.dev Compatibility Layer
   ============================================================= */

```

#### **4. Compiling and Running**

To run an exercise (e.g., inside the `7-6` directory), use the following command. This tells GCC to look in the `../munit` folder for both the `.c` source and the `.h` headers.

```bash
# Compile
gcc main.c exercise.c ../munit/munit.c -I../munit -o test_program

# Run
./test_program

```

* `main.c`: The test runner (Boot.dev provided).
* `exercise.c`: Your solution code.
* `../munit/munit.c`: The munit library implementation.
* `-I../munit`: **Crucial**. Adds the munit directory to the include path so `#include "bootlib.h"` works.
