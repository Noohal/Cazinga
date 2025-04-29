#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

Token_Queue *token_queue_create()
{
	Token_Queue *queue = (Token_Queue*)malloc(sizeof(Token_Queue));
	queue->elements = (Token**)malloc(sizeof(Token));
	queue->count = 0;
	queue->capacity = 1;
	queue->push = queue_push;
	queue->pop = queue_pop;
	return queue;
}

void token_queue_free(Token_Queue *queue)
{
	free(queue->elements);
	free(queue);
	queue = NULL;
}

void queue_push(Token_Queue *queue, Token *item)
{
}

Token *queue_pop(Token_Queue *queue)
{
	return NULL;
}

