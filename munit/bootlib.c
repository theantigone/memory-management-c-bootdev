#include "bootlib.h"
// Undefine macros so we can call the real standard library functions
#undef realloc
#undef malloc
#undef calloc
#undef free
#include <stdlib.h>

size_t boot_global_last_realloc_size = 0;
int boot_global_realloc_count = 0;
size_t boot_global_last_alloc_size = 0;

// Registry to track freed pointers
#define MAX_FREED_PTRS 4096
static void *freed_ptrs[MAX_FREED_PTRS];
static int freed_ptr_count = 0;

void *boot_realloc_interceptor(void *ptr, size_t size) {
    boot_global_last_realloc_size = size;
    boot_global_realloc_count++;
    return realloc(ptr, size);
}

void *boot_malloc_interceptor(size_t size) {
    boot_global_last_alloc_size = size;
    return malloc(size);
}

void *boot_calloc_interceptor(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

// Intercept free() to record the pointer
void boot_free_interceptor(void *ptr) {
    if (ptr == NULL) return;

    // Log the pointer as freed
    if (freed_ptr_count < MAX_FREED_PTRS) {
        freed_ptrs[freed_ptr_count++] = ptr;
    }

    free(ptr);
}

// Check if a pointer exists in our freed log
bool boot_is_freed(void *ptr) {
    for (int i = 0; i < freed_ptr_count; i++) {
        if (freed_ptrs[i] == ptr) {
            return true;
        }
    }
    return false;
}
