#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
  int *data = malloc(sizeof(int));
  *pointer_pointer = data;
  *data = value;
}

