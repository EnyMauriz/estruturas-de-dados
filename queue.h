#ifndef QUEUE
#define QUEUE
#include <stdbool.h>

// Estrutura para um n� na fila.
typedef struct _queueQueueNode QueueNode;

// Estrutura para a fila.
typedef struct _queue Queue;

// Fun��o que cria uma nova fila.
Queue* createQueue();

// Fun��o que destr�i uma fila.
void destroyQueue(Queue** queue_ref);

// Fun��o que cria um novo n� solto.
QueueNode* createQueueNode(int value);

// Fun��o que verifica se a fila est� vazia.
bool isQueueEmpty(Queue* queue);

// Fun��o que enfileira um novo n� na fila.
void enqueue(Queue* queue, int value);

// Fun��o que desenfileira um n� da fila.
int dequeue(Queue* queue);

// Fun��o que retorna o elemento da frente da fila sem remov�-lo.
int front(Queue* queue);

// Fun��o que imprime os elementos da fila.
void printQueue(Queue* queue);

// Fun��o que conta quantos elementos h� na fila.
int countQueue(Queue* queue);

#endif
