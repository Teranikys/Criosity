//
// Created by Teranikys on 8/17/2024.
//

#include <stdlib.h>

#include "memory.h"

void* reallocate(void *pointer, const size_t oldSize, const size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void *result = realloc(pointer, newSize);
    if (result == NULL) {
        exit(1);
    }
    return result;
}