#ifndef QUEUE_H_
#define QUEUE_H_

struct queue {
  struct queueItem *first;
  struct queueItem *last;
};
typedef struct queue Queue;
struct queueItem {
  int item;
  struct queueItem *next;
  struct queueItem *previous;
};

Queue *queueAlloc();
void queueAdd(Queue *queue, int item);
int queuePop(Queue *queue);
void queueFree(Queue *queue);

#endif
