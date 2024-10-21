#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
// Estrutura para um n� na pilha.
typedef struct _stackNode{
	int value;
	struct _stackNode* prev;
	struct _stackNode* next;
} StackNode;

// Estrutura para a pilha.
typedef struct _stack{
	StackNode* begin;
	StackNode* end;
	int count;
} Stack;

// Fun��o que cria uma nova pilha.
Stack* createStack(){
	Stack* newStack = (Stack*) calloc(1, sizeof(Stack));
	if(newStack == NULL){
		fprintf(stderr, "Erro na aloca��o de uma nova pilha.\n");
        exit(EXIT_FAILURE);
	}
	return newStack;
}
	
// Fun��o que destr�i uma pilha.
void destroyStack(Stack** stack_ref){
	if (stack_ref == NULL || *stack_ref == NULL) {
    	return; // N�o h� pilha para destruir
	}
	Stack* stack = *stack_ref;
	StackNode* index = stack->end;
	StackNode* aux = NULL;
	while(index != NULL){
		aux = index;
		index = index->prev;
		free(aux);
	}
	free(stack);
	*stack_ref = NULL;
}

// Fun��o que cria um novo n�.
StackNode* createStackNode(int value){
	StackNode* newStackNode = (StackNode*) calloc(1, sizeof(StackNode));
	if(newStackNode == NULL){
		fprintf(stderr, "Erro na aloca��o de um novo n�.\n");
        exit(EXIT_FAILURE);
	}
	newStackNode->value = value;
	return newStackNode;
}
	
// Fun��o que verifica se a pilha est� vazia.
bool isStackEmpty(Stack* stack){
	return stack->begin == NULL;
}

// Fun��o que empilha um novo n� na pilha.
void push(Stack* stack, int value){
	StackNode* newStackNode = createStackNode(value);	
	if(isStackEmpty(stack)){
		stack->begin = newStackNode;
	}else{
		stack->end->next = newStackNode;
		newStackNode->prev = stack->end;
	}
	stack->end = newStackNode;
	stack->count++;
}
	
// Fun��o que desempilha um n� da pilha.
int pop(Stack* stack){
	if(isStackEmpty(stack)){
		return -1;
	}
	int aux = stack->end->value;
	StackNode* temp = stack->end;
	if(stack->end == stack->begin){
		stack->end = NULL;
		stack->begin = NULL;
	}else{
		stack->end = temp->prev;
		stack->end->next = NULL;
	}
	free(temp);
	stack->count--;
	return aux;
}
	
// Fun��o que retorna o elemento do topo da pilha sem remov�-lo.
int peek(Stack* stack){
	if(isStackEmpty(stack)){
		fprintf(stderr, "Erro: A pilha est� vazia. \n");
		return -1;
	}
	return stack->end->value;
}
	
// Fun��o que imprime os elementos da pilha.
void printStack(Stack* stack){
	if(isStackEmpty(stack)){
		puts("A pilha est� vazia.");
		return;
	}
	StackNode* index = stack->end;
	puts("Aqui est� a sua pilha:");
	puts("");
	while(index != NULL){
		printf("Valor: %d. \n", index->value);
		index = index->prev;
	}
	puts("");
	puts("Fim da pilha.");
}
	
// Fun��o que conta quantos elementos h� na pilha.
int countStack(Stack* stack){
	return stack->count;
}

