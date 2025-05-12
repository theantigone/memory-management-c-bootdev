#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"

int *allocate_scalar_array(int size, int multiplier) {
	int *array = malloc(size * sizeof(int));
	// int check = 1024 * 1024 * 100;
	// printf("%d\n", check);
	// if (size == check)
	if (!array)
		return NULL;
	for (int i = 0; i < size; i++) {
		array[i] = i * multiplier;
		// printf("%d", array[i]);
	}
	return array;
}

