#include "common.h"
#include "structs/chunk.h"
#include "structs/debug.h"
#include "structs/vm.h"

int main(int argc, const char* argv[])
{
    VM vm;
    initVM(&vm);

    Chunk chunk;

    initChunk(&chunk);

    printf("======CHUNK DISSASEMBLY======\n\n");

    int constant = addConstant(&chunk, 1.2);
    int constant1 = addConstant(&chunk, 2);

    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant1, 123);
    writeChunk(&chunk, OP_NEGATE, 123);
    writeChunk(&chunk, OP_ADD, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    printf("\n\n======CHUNK DISSASEMBLY DONE======\n\n");

    interpret(&vm, &chunk);

    freeVM(&vm);
    freeChunk(&chunk);
    return 0;
}