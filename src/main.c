#include "graph.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_SIZE 5

int main() {
  Queue *queue = queueAlloc();
  queueAdd(queue, 1);
  queueAdd(queue, 2);
  queueAdd(queue, 3);
  queueAdd(queue, 4);
  queueAdd(queue, 5);
  queueAdd(queue, 6);
  printf("%d\n", queuePop(queue));
  printf("%d\n", queuePop(queue));
  printf("%d\n", queuePop(queue));
  printf("%d\n", queuePop(queue));
  printf("%d\n", queuePop(queue));
  printf("%d\n", queuePop(queue));
  queueFree(queue);
  Stack *stack = stackAlloc();
  stackAdd(stack, 1);
  stackAdd(stack, 2);
  stackAdd(stack, 3);
  stackAdd(stack, 4);
  stackAdd(stack, 5);
  stackAdd(stack, 6);
  printf("%d\n", stackPop(stack));
  printf("%d\n", stackPop(stack));
  printf("%d\n", stackPop(stack));
  printf("%d\n", stackPop(stack));
  printf("%d\n", stackPop(stack));
  printf("%d\n", stackPop(stack));
  stackFree(stack);

  struct vertexList *graph = vertexAlloc(GRAPH_SIZE);
  vertexAdd(graph, 0, 1);
  vertexAdd(graph, 1, 2);
  vertexAdd(graph, 1, 0);
  vertexAdd(graph, 2, 3);
  vertexAdd(graph, 3, 4);
  vertexAdd(graph, 1, 4);

  for (int j = 0; j < GRAPH_SIZE; j++) {
    printf("%d:", j);
    for (struct vertex *i = graph[j].first; i != NULL; i = i->next) {
      printf(" %ld,", i->number);
    }
    printf("\n");
  }
}

