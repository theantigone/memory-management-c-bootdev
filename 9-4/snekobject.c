#include "snekobject.h"
#include <stdlib.h>
#include <string.h>

snek_object_t *new_snek_string(char *value) {
  // ?
	snek_object_t*ptr=malloc(sizeof(snek_object_t));
	if(!ptr)
		return NULL;
	size_t len=strlen(value);
	ptr->kind=STRING;
	ptr->data.v_string=malloc(len+1);
	if(!ptr->data.v_string){
		free(ptr->data.v_string);
		return NULL;
	}
	strcpy(ptr->data.v_string,value);
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

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

