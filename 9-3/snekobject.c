#include "snekobject.h"
#include <stdlib.h>

snek_object_t *new_snek_float(float value) {
  // ?
	snek_object_t*ptr=malloc(sizeof(snek_object_t));
	if(!ptr)
		return NULL;
	ptr->kind=FLOAT;
	ptr->data.v_float=value;
	return ptr;
}

// don't touch below this line

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

