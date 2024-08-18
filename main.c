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


    const int constant1 = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant1, 1);

    writeChunk(&chunk, OP_RETURN, 1);

    // disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}
