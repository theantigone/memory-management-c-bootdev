#include "snekstack.h"
#include "stdlib.h"
#include <string.h>

void stack_push_multiple_types(stack_t *s) {
  // ?
	float*ptr=malloc(sizeof(float));
	*ptr=3.14;
	stack_push(s,(void*)ptr);
	char*constant="Sneklang is blazingly slow!";
	size_t len=strlen(constant)+1;
	char*tmp=malloc(sizeof(char)*len);
	strcpy(tmp,constant);
	stack_push(s,tmp);
}

