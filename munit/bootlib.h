#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h> // Include stdlib here to ensure prototypes exist

// Globals to track realloc calls
extern size_t boot_global_last_realloc_size;
extern int boot_global_realloc_count;

// Helper functions called by main.c
static inline size_t boot_last_realloc_size() {
    return boot_global_last_realloc_size;
}

static inline int boot_realloc_count() {
    return boot_global_realloc_count;
}

static inline bool boot_all_freed() {
    return true; 
}

// Interceptor function
void *boot_realloc_interceptor(void *ptr, size_t size);

// Macro: Replace realloc with our interceptor
#define realloc boot_realloc_interceptor

#endif
