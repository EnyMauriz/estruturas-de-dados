#ifndef QUEUE
#define QUEUE
#include <stdbool.h>

// Estrutura para um nó na fila.
typedef struct _queueQueueNode QueueNode;

// Estrutura para a fila.
typedef struct _queue Queue;

// Função que cria uma nova fila.
Queue* createQueue();

// Função que destrói uma fila.
void destroyQueue(Queue** queue_ref);

// Função que cria um novo nó solto.
QueueNode* createQueueNode(int value);

// Função que verifica se a fila está vazia.
bool isQueueEmpty(Queue* queue);

// Função que enfileira um novo nó na fila.
void enqueue(Queue* queue, int value);

// Função que desenfileira um nó da fila.
int dequeue(Queue* queue);

// Função que retorna o elemento da frente da fila sem removê-lo.
int front(Queue* queue);

// Função que imprime os elementos da fila.
void printQueue(Queue* queue);

// Função que conta quantos elementos há na fila.
int countQueue(Queue* queue);

#endif
