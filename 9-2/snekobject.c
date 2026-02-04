#include "snekobject.h"
#include <stdlib.h>

snek_object_t *new_snek_integer(int value) {
  // ?
	snek_object_t* ptr=malloc(sizeof(snek_object_t));
	if(!ptr)
		return NULL;
	ptr->kind=INTEGER;
	ptr->data.v_int=value;
	return ptr;
}

