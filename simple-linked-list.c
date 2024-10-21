#include <stdio.h>
#include <stdlib.h>
#include "simple-linked-list.h"

// Estrutura para o n� na cabe�a da lista.
typedef struct _simpleLinkedList {
	SimpleNode* begin;
	SimpleNode* end;
	int count;
} SimpleLinkedList;

// Estrutura para um n� qualquer.
typedef struct _simpleNode {
	int value;
	struct _simpleNode* next;
} SimpleNode;

// Fun��o que cria uma nova lista.
SimpleLinkedList* createList() {
    SimpleLinkedList* newList = (SimpleLinkedList*) calloc(1, sizeof(SimpleLinkedList));
    return newList;
}

// Fun��o que destroi uma lista.
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

// Fun��o que cria um novo n� solto.
SimpleNode* createSimpleNode(int value){
	SimpleNode* newSimpleNode = (SimpleNode*) calloc(1, sizeof(SimpleNode));
	if(newSimpleNode == NULL){
		fprintf(stderr, "Erro: falha na aloca��o de mem�ria.\n");
        exit(EXIT_FAILURE);
	}
	newSimpleNode->value = value;
	return newSimpleNode;
}
	
// Fun��o que verifica se a lista est� vazia;
bool isListEmpty(SimpleLinkedList* list){
	return list->begin == NULL;
}

//Fun��o que cria um novo n� e o insere no in�cio da lista.
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
	
// Fun��o que cria um novo n� e o insere no fim da lista.
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
	
// Fun��o que imprime uma lista.
void printList(SimpleLinkedList* list){
	if(isListEmpty(list)){
		printf("A lista est� vazia.");
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
	
// Fun��o que conta quantos elementos h� na lista.
int countList(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista est� vazia.");
		return 0;
	}else{
		return list->count;
	}
}
	
// Fun��o que retorna o primeiro elemento da lista.
void firstSimpleNode(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista est� vazia.");
	}else{
	printf("Este � o primeiro elemento da sua lista: %d.", list->begin->value);
	}
}
	
// Fun��o que retorna o �ltimo elemento da lista.
void lastSimpleNode(SimpleLinkedList* list){
	if(isListEmpty(list)){
		puts("A lista est� vazia.");
	}else{
		printf("Este � o �ltimo elemento da sua lista: %d.", list->end->value);
	}
}

// Fun��o que retorna um elemento na lista buscado pelo usu�rio.
void findSimpleNode(SimpleLinkedList* list, int search){
	if(isListEmpty(list)){
		puts("A lista est� vazia. \n");
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
	printf("O elemento %d n�o foi encontrado na lista. \n", search);
}
	
// Fun��o que apaga um, e somente um, elemento da lista.
void removeSimpleNode(SimpleLinkedList* list, int search){
	if(isListEmpty(list)){
		puts("A lista est� vazia.");
		return;
	}
	SimpleNode* index = list->begin;
	SimpleNode* aux = NULL;
	
	while(index != NULL && index->value != search){
		aux = index;
		index = index->next;
	}
	
	if(index == NULL){
		printf("Elemento %d n�o encontrado.\n", search);
	}else{
		// Verificando se o elemento est� no final da lista
		if(index == list->end){
			list->end = aux;
		}
		// Verificando se o elemento est� no in�cio da lista
		if(index == list->begin){
			list->begin = index->next;
		}else{
			aux->next = index->next;
		}
		free(index);
	}
	list->count--;
}
