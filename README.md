## Boot.dev Memory Management Free Membership

[Learn Memory Management in C](https://www.boot.dev/courses/learn-memory-management-c)

### How it works:
1. Download the [``µnit`` framework](https://github.com/nemequ/munit/)
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
