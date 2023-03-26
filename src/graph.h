#ifndef GRAPH_H_
#define GRAPH_H_

#include <stddef.h>

struct vertex {
	size_t number;
	struct vertex *next;
};

struct vertexList {
	struct vertex *first;
	struct vertex *last;
};

struct vertexList *vertexAlloc(size_t length);
void vertexAdd(struct vertexList *v, size_t toWhich, size_t whichOne);

#endif

