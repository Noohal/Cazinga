#ifndef __CONTAINER_H
#define __CONTAINER_H

#include "token.h"

typedef struct
{
	token_t *elements;
	unsigned int count;
	unsigned int capacity;
} token_queue_t;

token_queue_t *tqueue_create();
void tqueue_free(token_queue_t *tq);

void tqueue_push(token_queue_t *tq, token_t item);
token_t *tqueue_pop(token_queue_t *tq);

#endif // __CONTAINER_H
