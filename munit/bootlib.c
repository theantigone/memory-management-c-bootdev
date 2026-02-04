#include "bootlib.h" // 1. Include this FIRST to define the macro
#undef realloc       // 2. UNDEFINE it immediately so we can see the real stdlib realloc
#include <stdlib.h>  // 3. Include stdlib to get the real function

size_t boot_global_last_realloc_size = 0;
int boot_global_realloc_count = 0;

void *boot_realloc_interceptor(void *ptr, size_t size) {
    boot_global_last_realloc_size = size;
    boot_global_realloc_count++;
    // Now this calls the REAL realloc from stdlib
    return realloc(ptr, size);
}
