#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queueAlloc() {
  Queue *new = malloc(sizeof(Queue));
  new->first = NULL;
  new->last = NULL;
  return new;
}

void queueAdd(Queue *queue, int item) {
  struct queueItem *new = malloc(sizeof(struct queueItem));
  new->item = item;
  if (queue->first) {
    new->next = queue->last;
    new->previous = NULL;
    queue->last->previous = new;
    queue->last = new;
  } else {
    new->next = NULL;
    new->previous = NULL;
    queue->first = new;
    queue->last = new;
  }
}

int queuePop(Queue *queue) {
  if (!queue->first) {
    return -1;
  }
  int out = queue->first->item;
  queue->first = queue->first->previous;
  return out;
}

void queueFree(Queue *queue) {
  struct queueItem *qi = queue->last;
  struct queueItem *t = NULL;
  while (qi) {
    // printf("Address:");
    // printf("%p\n", (void *)qi);
    t = qi->next;
    free(qi);
    qi = t;
  }
  free(queue);
}
