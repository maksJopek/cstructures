#include <stdlib.h>
#include "graph.h"

struct vertexList *vertexAlloc(size_t length) {
	struct vertexList *vertices = malloc(sizeof(*vertices) * length);
	for(size_t i = 0; i < length; i++) {
		vertices[i].first = NULL;
		vertices[i].last = NULL;
	}
	return vertices;
}

void vertexAdd(
	struct vertexList *list, size_t toWhich, size_t whichOne
) {
	struct vertex *new = malloc(sizeof(*new));
	new->number = whichOne;
	new->next = NULL;
	if(list[toWhich].first == NULL) {
		list[toWhich].first = new;
		list[toWhich].last = new;
		return;
	}
	list[toWhich].last->next = new;
	list[toWhich].last = new;
}

