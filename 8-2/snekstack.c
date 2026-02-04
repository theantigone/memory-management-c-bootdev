#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj) {
  // ?
	if(stack->count==stack->capacity){
		stack->capacity*=2;
		stack->data=realloc(stack->data,stack->capacity*sizeof(void*));
		if(!stack->data){
			stack->capacity/=2;
			exit(1);
		}
	}
	stack->data[stack->count]=obj;
	stack->capacity++;
}

// don't touch below this line

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}

