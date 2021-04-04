#ifndef module_vm_h
#define module_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct
{
	Chunk* chunk;
	Value stack[STACK_MAX];
	Value* stackTop;
	uint8_t* ip;
} VM;

typedef enum
{
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM(VM* vm);
void freeVM(VM* vm);

InterpretResult interpret(VM* vm, Chunk* chunk);
InterpretResult interpret(const char* source);

void push(VM* vm, Value value);
Value pop(VM* vm);

#endif