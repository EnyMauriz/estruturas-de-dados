#include <stdio.h>
#include <stdlib.h>
#include "simple-linked-list.h"

// Estrutura para o nó na cabeça da lista.
typedef struct _simpleLinkedList {
	SimpleNode* begin;
	SimpleNode* end;
	int count;
} SimpleLinkedList;

// Estrutura para um nó qualquer.
typedef struct _simpleNode {
	int value;
	struct _simpleNode* next;
} SimpleNode;

// Função que cria uma nova lista.
SimpleLinkedList* createList() {
    SimpleLinkedList* newList = (SimpleLinkedList*) calloc(1, sizeof(SimpleLinkedList));
    return newList;
}

// Função que destroi uma lista.
void destroyList(SimpleLinkedList** list_ref){
	SimpleLinkedList* list = *list_ref;
	SimpleNode* index = list->begin;
	SimpleNode* aux = NULL;
	
	while (index != NULL){
		aux = index;
		index = index->next;
		free(aux);
	}
	free(list);
	*list_ref = NULL;
}

// Função que cria um novo nó solto.
SimpleNode* createSimpleNode(int value){
	SimpleNode* newSimpleNode = (SimpleNode*) calloc(1, sizeof(SimpleNode));
	if(newSimpleNode == NULL){
		fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
	}
	newSimpleNode->value = value;
	return newSimpleNode;
}
	
// Função que verifica se a lista está vazia;
bool isListEmpty(SimpleLinkedList* list){
	return list->begin == NULL;
}

//Função que cria um novo nó e o insere no início da lista.
void addSimpleNodeFirst(SimpleLinkedList* list, int value){
	SimpleNode* newSimpleNode = createSimpleNode(value);
	if(isListEmpty(list)){
		list->begin = newSimpleNode;
		list->end = newSimpleNode;
	}else{
		SimpleNode* aux = list->begin;
		list->begin = newSimpleNode;
		newSimpleNode->next = aux;
	}
	list->count++;
}
	
// Função que cria um novo nó e o insere no fim da lista.
void addSimpleNodeLast(SimpleLinkedList* list, int value){
	SimpleNode* newSimpleNode = createSimpleNode(value);
	if(isListEmpty(list)){
		list->begin = newSimpleNode;
		list->end = newSimpleNode;
	}else{
		list->end->next = newSimpleNode;
		list->end = newSimpleNode;	
	}
	list->count++;
}
	
// Função que imprime uma lista.
void printList(SimpleLinkedList* list){
	if(isListEmpty(list)){
		printf("A lista está vazia.");
	}else{
		SimpleNode* index = list->begin;
		puts("Elementos da lista:");
		while(index != NULL){
			printf("Valor: %d. \n", index->value);
			index = index->next;
		}
		puts("Fim da lista.");
	}
}
	
// Função que conta quantos elementos há na lista.
int countList(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista está vazia.");
		return 0;
	}else{
		return list->count;
	}
}
	
// Função que retorna o primeiro elemento da lista.
void firstSimpleNode(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista está vazia.");
	}else{
	printf("Este é o primeiro elemento da sua lista: %d.", list->begin->value);
	}
}
	
// Função que retorna o último elemento da lista.
void lastSimpleNode(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista está vazia.");
	}else{
		printf("Este é o último elemento da sua lista: %d.", list->end->value);
	}
}

// Função que retorna um elemento na lista buscado pelo usuário.
void findSimpleNode(SimpleLinkedList* list, int search){
	if(isListEmpty(list)){
		puts("A lista está vazia. \n");
		return;
	}
	SimpleNode* index = list->begin;
	while(index != NULL){
		if(index->value == search){
			printf("O elemento %d foi encontrado na lista. \n", search);
			return;
		}
		index = index->next;
	}
	printf("O elemento %d não foi encontrado na lista. \n", search);
}
	
// Função que apaga um, e somente um, elemento da lista.
void removeSimpleNode(SimpleLinkedList* list, int search){
	if(isListEmpty(list)){
		puts("A lista está vazia.");
		return;
	}
	SimpleNode* index = list->begin;
	SimpleNode* aux = NULL;
	
	while(index != NULL && index->value != search){
		aux = index;
		index = index->next;
	}
	
	if(index == NULL){
		printf("Elemento %d não encontrado.\n", search);
	}else{
		// Verificando se o elemento está no final da lista
		if(index == list->end){
			list->end = aux;
		}
		// Verificando se o elemento está no início da lista
		if(index == list->begin){
			list->begin = index->next;
		}else{
			aux->next = index->next;
		}
		free(index);
	}
	list->count--;
}
