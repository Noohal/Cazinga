#include "container.h"

#include <stdio.h>
#include <stdlib.h>

token_queue_t *tqueue_create()
{
	token_queue_t *q = (token_queue_t*)calloc(1, sizeof(token_queue_t));
	q->capacity = 1;
	q->elements = (token_t*)calloc(q->capacity, sizeof(token_t));
	q->count = 0;
	return q;
}

void tqueue_free(token_queue_t *tq)
{
	free(tq->elements);
	tq->elements = NULL;
	tq->count = 0;
	tq->capacity = 0;
	tq = NULL;
}

void tqueue_push(token_queue_t *tq, token_t item)
{
	if (tq->count >= tq->capacity)
	{
		fprintf(stdout, "### Exceeding queue capacity, reallocating memory...\n");
		tq->capacity *= 2;
		tq->elements = realloc(tq->elements, tq->capacity*sizeof(token_t));
	}
	tq->elements[tq->count++] = item;
}

token_t *tqueue_pop(token_queue_t *tq)
{
	if (tq->count < 1)
	{
		//fprintf(stderr, "ERROR: Empty Queue!");
		return NULL;
	}
	token_t *popped = tq->elements++;
	tq->count--;
	return popped;	
}
