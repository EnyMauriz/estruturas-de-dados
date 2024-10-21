#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Estrutura para um nó na fila.
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

// Função que cria uma nova fila.
Queue* createQueue(){
	Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
	return newQueue;
}
	
// Função que destrói uma fila.
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

// Função que cria um novo nó solto.
QueueNode* createQueueNode(int value){
	QueueNode* newQueueNode = (QueueNode*)calloc(1, sizeof(QueueNode));
	newQueueNode->value = value;
	return newQueueNode;
}

// Função que verifica se a fila está vazia.
bool isQueueEmpty(Queue* queue){
	return queue->begin == NULL;
}

// Função que enfileira um novo nó na fila.
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

// Função que desenfileira um nó da fila.
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
	
// Função que retorna o elemento da frente da fila sem removê-lo.
int front(Queue* queue){
	if(isQueueEmpty(queue)){
		return -1;
	}else{
		return queue->begin->value;
	}
}
	
// Função que imprime os elementos da fila.
void printQueue(Queue* queue){
	if(isQueueEmpty(queue)){
		puts("A fila está vazia.");
		return;
	}
	puts("Esta é a sua fila atual:");
	QueueNode* index = queue->begin;
	while(index != NULL){
		printf("Valor: %d. \n", index->value);
		index = index->next;
	}
	puts("Fim da fila.");
}
	
// Função que conta quantos elementos há na fila.
int countQueue(Queue* queue){
	if(isQueueEmpty(queue)){
		return -1;
	}
	return queue->count;
}
