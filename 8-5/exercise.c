#include "snekstack.h"
#include "stdlib.h"

void scary_double_push(stack_t *s) {
  // ?
	stack_push(s,(void*)1337);
	int*tmp=malloc(sizeof(int));
	*tmp=1024;
	stack_push(s,(void*)tmp);
}

