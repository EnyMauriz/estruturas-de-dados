#ifndef STACK
#define STACK
#include <stdbool.h>

// Estrutura para um nó na pilha.
typedef struct _stackNode StackStackNode;

// Estrutura para a pilha.
typedef struct _stack Stack;

// Função que cria uma nova pilha.
Stack* createStack();

// Função que destrói uma pilha.
void destroyStack(Stack** stack_ref);

// Função que cria um novo nó solto.
StackStackNode* createStackStackNode(int value);

// Função que verifica se a pilha está vazia.
bool isStackEmpty(Stack* stack);

// Função que empilha um novo nó na pilha.
void push(Stack* stack, int value);

// Função que desempilha um nó da pilha.
int pop(Stack* stack);

// Função que retorna o elemento do topo da pilha sem removê-lo.
int peek(Stack* stack);

// Função que imprime os elementos da pilha.
void printStack(Stack* stack);

// Função que conta quantos elementos há na pilha.
int countStack(Stack* stack);

#endif
