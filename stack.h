#ifndef STACK
#define STACK
#include <stdbool.h>

// Estrutura para um n� na pilha.
typedef struct _stackNode StackStackNode;

// Estrutura para a pilha.
typedef struct _stack Stack;

// Fun��o que cria uma nova pilha.
Stack* createStack();

// Fun��o que destr�i uma pilha.
void destroyStack(Stack** stack_ref);

// Fun��o que cria um novo n� solto.
StackStackNode* createStackStackNode(int value);

// Fun��o que verifica se a pilha est� vazia.
bool isStackEmpty(Stack* stack);

// Fun��o que empilha um novo n� na pilha.
void push(Stack* stack, int value);

// Fun��o que desempilha um n� da pilha.
int pop(Stack* stack);

// Fun��o que retorna o elemento do topo da pilha sem remov�-lo.
int peek(Stack* stack);

// Fun��o que imprime os elementos da pilha.
void printStack(Stack* stack);

// Fun��o que conta quantos elementos h� na pilha.
int countStack(Stack* stack);

#endif
