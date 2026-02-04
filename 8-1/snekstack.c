#include "snekstack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  // ?
	stack_t* stack=malloc(sizeof(stack_t));
	if(!stack)
		return NULL;
	stack->count=0;
	stack->capacity=capacity;
	stack->data=malloc(capacity*sizeof(void*));
	if(!stack->data){
		free(stack);
		return NULL;
	}
	return stack;
}

