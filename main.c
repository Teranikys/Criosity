#include <stdio.h>

#include "common.h"
#include "vm.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    const int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    const int constant1 = addConstant(&chunk, 4.4);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant1, 1);

    writeChunk(&chunk, OP_ADD, 1);

    const int constant2 = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constant2, 2);

    writeChunk(&chunk, OP_DIVIDE, 2);
    writeChunk(&chunk, OP_NEGATE, 2);

    writeChunk(&chunk, OP_RETURN, 2);

    // disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}
