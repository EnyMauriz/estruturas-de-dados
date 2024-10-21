#ifndef SIMPLELINKEDLIST
#define SIMPLELINKEDLIST
#include <stdbool.h>
// Estrutura para o nó na cabeça da lista.
typedef struct _simpleLinkedList SimpleLinkedList;

// Estrutura para um nó qualquer.
typedef struct _simpleNode SimpleNode;

// Função que cria uma nova lista.
SimpleLinkedList* createList();

// Função que destroi uma lista.
void destroyList(SimpleLinkedList** list_ref);

// Função que cria um novo nó solto.
SimpleNode* createSimpleNode(int value);

// Função que verifica se a lista está vazia;
bool isListEmpty(SimpleLinkedList* list);

// Função que cria um novo nó e o insere no início da lista.
void addSimpleNodeFirst(SimpleLinkedList* list, int value);

// Função que cria um novo nó e o insere no fim da lista.
void addSimpleNodeLast(SimpleLinkedList* list, int value);

// Função que imprime uma lista.
void printList(SimpleLinkedList* list);

// Função que conta quantos elementos há na lista.
int countList(SimpleLinkedList* list);

// Função que retorna o primeiro elemento da lista.
void firstSimpleNode(SimpleLinkedList* list);

// Função que retorna o último elemento da lista.
void lastSimpleNode(SimpleLinkedList* list);

// Função que retorna um elemento na lista buscado pelo usuário.
void findSimpleNode(SimpleLinkedList* list, int search);

// Função que apaga um, e somente um, elemento da lista.
void removeSimpleNode(SimpleLinkedList* list, int search);

#endif
