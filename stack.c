#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
// Estrutura para um nó na pilha.
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

// Função que cria uma nova pilha.
Stack* createStack(){
	Stack* newStack = (Stack*) calloc(1, sizeof(Stack));
	if(newStack == NULL){
		fprintf(stderr, "Erro na alocação de uma nova pilha.\n");
        exit(EXIT_FAILURE);
	}
	return newStack;
}
	
// Função que destrói uma pilha.
void destroyStack(Stack** stack_ref){
	if (stack_ref == NULL || *stack_ref == NULL) {
    	return; // Não há pilha para destruir
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

// Função que cria um novo nó.
StackNode* createStackNode(int value){
	StackNode* newStackNode = (StackNode*) calloc(1, sizeof(StackNode));
	if(newStackNode == NULL){
		fprintf(stderr, "Erro na alocação de um novo nó.\n");
        exit(EXIT_FAILURE);
	}
	newStackNode->value = value;
	return newStackNode;
}
	
// Função que verifica se a pilha está vazia.
bool isStackEmpty(Stack* stack){
	return stack->begin == NULL;
}

// Função que empilha um novo nó na pilha.
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
	
// Função que desempilha um nó da pilha.
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
	
// Função que retorna o elemento do topo da pilha sem removê-lo.
int peek(Stack* stack){
	if(isStackEmpty(stack)){
		fprintf(stderr, "Erro: A pilha está vazia. \n");
		return -1;
	}
	return stack->end->value;
}
	
// Função que imprime os elementos da pilha.
void printStack(Stack* stack){
	if(isStackEmpty(stack)){
		puts("A pilha está vazia.");
		return;
	}
	StackNode* index = stack->end;
	puts("Aqui está a sua pilha:");
	puts("");
	while(index != NULL){
		printf("Valor: %d. \n", index->value);
		index = index->prev;
	}
	puts("");
	puts("Fim da pilha.");
}
	
// Função que conta quantos elementos há na pilha.
int countStack(Stack* stack){
	return stack->count;
}

