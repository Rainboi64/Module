#ifndef module_chunk_h
#define module_chunk_h

#include "../common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

typedef struct {
  ValueArray constants;
  int count;
  int capacity;
  uint8_t* code;
  int* lines;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

void freeChunk(Chunk* chunk);


#endif