#include "common.h"
#include "structs/chunk.h"
#include "structs/debug.h"
#include "structs/vm.h"

int main()
{
    VM vm;
    initVM(&vm);

    Chunk chunk;

    initChunk(&chunk);

    printf("======CHUNK DISSASEMBLY======\n\n");

    int constant = addConstant(&chunk, 1.2);

    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    printf("\n\n======CHUNK DISSASEMBLY DONE======\n\n");

    interpret(&vm, &chunk);

    freeVM(&vm);
    freeChunk(&chunk);
    return 0;
}