//
// Created by Teranikys on 8/17/2024.
//

#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCapacity, newCapacity) \
    (type*)reallocate(pointer, sizeof(type) * (oldCapacity), \
        sizeof(type) * (newCapacity))

#define FREE_ARRAY(type, pointer, oldCapacity) \
    reallocate(pointer, sizeof(type) * oldCapacity, 0)

void* reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif //MEMORY_H
