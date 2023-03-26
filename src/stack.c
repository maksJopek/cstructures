#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stackAlloc() {
  Stack *new = malloc(sizeof(Stack));
  new->first = NULL;
  new->last = NULL;
  return new;
}

void stackAdd(Stack *stack, int item) {
  struct queueItem *new = malloc(sizeof(struct queueItem));
  new->item = item;
  if (stack->first) {
    // printf("stack->first is NOT NULL");
    new->next = NULL;
    new->previous = stack->first;
    stack->first->next = new;
    stack->first = new;
  } else {
    // printf("stack->first is NULL");
    new->next = NULL;
    new->previous = NULL;
    stack->first = new;
    stack->last = new;
  }
}

int stackPop(Stack *stack) {
  if (!stack->first) {
    return -1;
  }
  int out = stack->first->item;
  struct queueItem *toFree = stack->first;
  stack->first = toFree->previous;
  free(toFree);
  return out;
}

void stackFree(Stack *stack) {
  struct queueItem *s = stack->first;
  struct queueItem *t = NULL;
  while (s) {
    t = s->previous;
    free(s);
    s = t;
  }
  free(stack);
}
