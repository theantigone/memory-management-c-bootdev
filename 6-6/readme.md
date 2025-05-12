Note that on [boot.dev](https://www.boot.dev), the container probably has a memory cap of a few-hundred MiB (mebibytes, 1024 kibibytes), so when you run `a.out`, the `test_allocate_too_much` will most likely fail because most modern 64-bit machines can easily allocate around 419 MB (1024 * 1024 * 100 ints), but [boot.dev](https://www.boot.dev)'s runner is probably capped at a very low number.


Therefore, you'll see the comments in `exercise.c`, regarding the `check` integer variable. If you uncomment:
```
int check = 1024 * 1024 * 100;
if (size == check)
```
and comment out:
```
if (!array)
```
you'll see that the last test will pass.
