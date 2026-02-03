#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  // ?
	int *buffer=malloc(size*sizeof(size));
	if(!buffer)
		return 1;
	memcpy(vp1,vp2,size);
	free(buffer);
}

