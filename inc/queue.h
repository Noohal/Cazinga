#ifndef __QUEUE_H
#define __QUEUE_H

#include "token.h"

typedef struct Token_Queue
{
	Token **elements;
	int capacity;
	int count;
	void (*push)(struct Token_Queue*, Token*);
	Token *(*pop)(struct Token_Queue*);
} Token_Queue;

Token_Queue *token_queue_create();
void token_queue_free(Token_Queue *queue);

void queue_push(Token_Queue *queue, Token *item);
Token *queue_pop(Token_Queue *queue);

#endif // __QUEUE_H
