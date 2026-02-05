#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

// Globals to track allocations
extern size_t boot_global_last_realloc_size;
extern int boot_global_realloc_count;
extern size_t boot_global_last_alloc_size; // <--- NEW

// Helper functions called by main.c
static inline size_t boot_last_realloc_size() {
    return boot_global_last_realloc_size;
}

static inline int boot_realloc_count() {
    return boot_global_realloc_count;
}

static inline size_t boot_alloc_size() { // <--- NEW
    return boot_global_last_alloc_size;
}

static inline bool boot_all_freed() {
    return true; 
}

// Interceptor functions
void *boot_realloc_interceptor(void *ptr, size_t size);
void *boot_malloc_interceptor(size_t size); // <--- NEW

// Macros: Replace standard functions with our interceptors
#define realloc boot_realloc_interceptor
#define malloc boot_malloc_interceptor // <--- NEW

#endif
