//
// Created by Teranikys on 8/17/2024.
//

#ifndef DEBUG_H
#define DEBUG_H

#include "chunk.h"

void disassembleChunk(const Chunk *chunk, const char *name);

int disassembleInstruction(const Chunk *chunk, int offset);

#endif //DEBUG_H
