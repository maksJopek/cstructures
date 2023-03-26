#ifndef STACK_H_
#define STACK_H_

#include "queue.h"

typedef struct queue Stack;

Stack *stackAlloc();
void stackAdd(Stack *stack, int item);
int stackPop(Stack *stack);
void stackFree(Stack *stack);

#endif
