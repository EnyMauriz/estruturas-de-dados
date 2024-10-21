#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Estrutura para um n� na fila.
typedef struct _queueQueueNode {
	int value;
	struct _queueQueueNode* prev;
	struct _queueQueueNode* next;
}QueueNode;

// Estrutura para a fila.
typedef struct _queue {
	QueueNode* begin;
	QueueNode* end;
	int count;
} Queue;

// Fun��o que cria uma nova fila.
Queue* createQueue(){
	Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
	return newQueue;
}
	
// Fun��o que destr�i uma fila.
void destroyQueue(Queue** queue_ref){
	if (queue_ref == NULL || *queue_ref == NULL) {
    	return;
	}
	Queue* queue = *queue_ref;
	QueueNode* index = queue->begin;
	QueueNode* aux = NULL;
	while(index != NULL){
		aux = index;
		index = index->next;
		free(aux);
	}
	free(queue);
	*queue_ref = NULL;
}

// Fun��o que cria um novo n� solto.
QueueNode* createQueueNode(int value){
	QueueNode* newQueueNode = (QueueNode*)calloc(1, sizeof(QueueNode));
	newQueueNode->value = value;
	return newQueueNode;
}

// Fun��o que verifica se a fila est� vazia.
bool isQueueEmpty(Queue* queue){
	return queue->begin == NULL;
}

// Fun��o que enfileira um novo n� na fila.
void enqueue(Queue* queue, int value){
	QueueNode* newQueueNode = createQueueNode(value);
	if(isQueueEmpty(queue)){
		queue->begin = newQueueNode;
	}else{
		queue->end->next = newQueueNode;
		newQueueNode->prev = queue->end;
	}
	queue->end = newQueueNode;
	queue->count++;
}

// Fun��o que desenfileira um n� da fila.
int dequeue(Queue* queue){
	if(isQueueEmpty(queue)){
		return -1;
	}
	int aux = queue->begin->value;
	QueueNode* temp = queue->begin;
	if(queue->begin == queue->end){
		queue->begin = NULL;
		queue->end = NULL;
	}else{
		queue->begin = temp->next;
		queue->begin->prev = NULL;
	}
	free(temp);
	queue->count--;
	return aux;
}
	
// Fun��o que retorna o elemento da frente da fila sem remov�-lo.
int front(Queue* queue){
	if(isQueueEmpty(queue)){
		return -1;
	}else{
		return queue->begin->value;
	}
}
	
// Fun��o que imprime os elementos da fila.
void printQueue(Queue* queue){
	if(isQueueEmpty(queue)){
		puts("A fila est� vazia.");
		return;
	}
	puts("Esta � a sua fila atual:");
	QueueNode* index = queue->begin;
	while(index != NULL){
		printf("Valor: %d. \n", index->value);
		index = index->next;
	}
	puts("Fim da fila.");
}
	
// Fun��o que conta quantos elementos h� na fila.
int countQueue(Queue* queue){
	if(isQueueEmpty(queue)){
		return -1;
	}
	return queue->count;
}
