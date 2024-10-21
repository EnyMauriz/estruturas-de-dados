#ifndef SIMPLELINKEDLIST
#define SIMPLELINKEDLIST
#include <stdbool.h>
// Estrutura para o n� na cabe�a da lista.
typedef struct _simpleLinkedList SimpleLinkedList;

// Estrutura para um n� qualquer.
typedef struct _simpleNode SimpleNode;

// Fun��o que cria uma nova lista.
SimpleLinkedList* createList();

// Fun��o que destroi uma lista.
void destroyList(SimpleLinkedList** list_ref);

// Fun��o que cria um novo n� solto.
SimpleNode* createSimpleNode(int value);

// Fun��o que verifica se a lista est� vazia;
bool isListEmpty(SimpleLinkedList* list);

// Fun��o que cria um novo n� e o insere no in�cio da lista.
void addSimpleNodeFirst(SimpleLinkedList* list, int value);

// Fun��o que cria um novo n� e o insere no fim da lista.
void addSimpleNodeLast(SimpleLinkedList* list, int value);

// Fun��o que imprime uma lista.
void printList(SimpleLinkedList* list);

// Fun��o que conta quantos elementos h� na lista.
int countList(SimpleLinkedList* list);

// Fun��o que retorna o primeiro elemento da lista.
void firstSimpleNode(SimpleLinkedList* list);

// Fun��o que retorna o �ltimo elemento da lista.
void lastSimpleNode(SimpleLinkedList* list);

// Fun��o que retorna um elemento na lista buscado pelo usu�rio.
void findSimpleNode(SimpleLinkedList* list, int search);

// Fun��o que apaga um, e somente um, elemento da lista.
void removeSimpleNode(SimpleLinkedList* list, int search);

#endif
