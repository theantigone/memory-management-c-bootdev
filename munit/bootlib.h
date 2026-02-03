#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stdbool.h>

// Mock implementation for local running.
// On Boot.dev, this checks if all allocated memory has been freed.
// Locally, we will assume true to allow tests to compile and run.
static inline bool boot_all_freed() {
    return true; 
}

#endif
