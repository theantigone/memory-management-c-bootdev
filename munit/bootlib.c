#include "bootlib.h" 
#undef realloc
#undef malloc       // <--- UNDEFINE malloc so we can call the real one
#include <stdlib.h>

size_t boot_global_last_realloc_size = 0;
int boot_global_realloc_count = 0;
size_t boot_global_last_alloc_size = 0; // <--- NEW

void *boot_realloc_interceptor(void *ptr, size_t size) {
    boot_global_last_realloc_size = size;
    boot_global_realloc_count++;
    return realloc(ptr, size);
}

// <--- NEW INTERCEPTOR
void *boot_malloc_interceptor(size_t size) {
    boot_global_last_alloc_size = size;
    return malloc(size);
}
