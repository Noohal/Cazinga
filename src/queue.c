#include "queue.h"

#include <stdlib.h>

Token_Queue *token_queue_create()
{
	Token_Queue *queue = (Token_Queue*)malloc(sizeof(Token_Queue));
	queue->count = 0;
	queue->capacity = 1;
	queue->push = queue_push;
	return queue;
}

void token_queue_free(Token_Queue *queue)
{
	free(queue);
	queue = NULL;
}

void queue_push(Token_Queue *queue, Token item)
{

}
