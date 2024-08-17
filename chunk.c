//
// Created by Teranikys on 8/17/2024.
//

#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

void freeChunk(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}

void writeChunk(Chunk *chunk, const uint8_t byte) {
    if (chunk->capacity == chunk->count) {
        // reallocate array and update capacity
        const int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(chunk->capacity);
        chunk->code = GROW_ARRAY(
            uint8_t,
            chunk->code,
            oldCapacity,
            chunk->capacity);
    }
    // just add a new element
    chunk->code[chunk->count++] = byte;
}
