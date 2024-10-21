#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simple-linked-list.h"
#include "stack.h"
#include "queue.h"

// Função para limpar a tela (Windows)
void clearScreen() {
    system("cls"); 
}

// Função para pausar até pressionar Enter
void pause() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// Menu para manipular a lista
void menuLinkedList(SimpleLinkedList* list) {
    int choice, value;

    do {
        clearScreen();
        printf("Manipulação de Lista:\n");
        printf("1. Adicionar nó no início\n");
        printf("2. Adicionar nó no fim\n");
        printf("3. Remover nó\n");
        printf("4. Imprimir lista\n");
        printf("5. Contar elementos\n");
        printf("6. Ver primeiro elemento\n");
        printf("7. Ver último elemento\n");
        printf("8. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &value);
                addSimpleNodeFirst(list, value);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &value);
                addSimpleNodeLast(list, value);
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &value);
                removeSimpleNode(list, value);
                break;
            case 4:
                printList(list);
                break;
            case 5:
                printf("Total de elementos: %d\n", countList(list));
                break;
            case 6:
                firstSimpleNode(list);
                break;
            case 7:
                lastSimpleNode(list);
                break;
            case 8:
                return;
            default:
                printf("Opção inválida.\n");
        }
        pause();
    } while (choice != 8);
}

// Menu para manipular a pilha
void menuStack(Stack* stack) {
    int choice, value;

    do {
        clearScreen();
        printf("Manipulação de Pilha:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Ver topo\n");
        printf("4. Imprimir pilha\n");
        printf("5. Contar elementos\n");
        printf("6. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value == -1)
                    printf("Pilha vazia.\n");
                else
                    printf("Desempilhado: %d\n", value);
                break;
            case 3:
                value = peek(stack);
                if (value == -1)
                    printf("Pilha vazia.\n");
                else
                    printf("Topo: %d\n", value);
                break;
            case 4:
                printStack(stack);
                break;
            case 5:
                printf("Total de elementos: %d\n", countStack(stack));
                break;
            case 6:
                return;
            default:
                printf("Opção inválida.\n");
        }
        pause();
    } while (choice != 6);
}

// Menu para manipular a fila
void menuQueue(Queue* queue) {
    int choice, value;

    do {
        clearScreen();
        printf("Manipulação de Fila:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Ver frente\n");
        printf("4. Imprimir fila\n");
        printf("5. Contar elementos\n");
        printf("6. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value == -1)
                    printf("Fila vazia.\n");
                else
                    printf("Desenfileirado: %d\n", value);
                break;
            case 3:
                value = front(queue);
                if (value == -1)
                    printf("Fila vazia.\n");
                else
                    printf("Frente: %d\n", value);
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                printf("Total de elementos: %d\n", countQueue(queue));
                break;
            case 6:
                return;
            default:
                printf("Opção inválida.\n");
        }
        pause();
    } while (choice != 6);
}

// Menu principal
int main() {
	setlocale(LC_ALL, "Portuguese");
    int choice;

    // Cria as estruturas
    SimpleLinkedList* list = createList();
    Stack* stack = createStack();
    Queue* queue = createQueue();

    do {
        clearScreen();
        printf("Menu Principal:\n");
        printf("1. Manipular Lista\n");
        printf("2. Manipular Pilha\n");
        printf("3. Manipular Fila\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                menuLinkedList(list);
                break;
            case 2:
                menuStack(stack);
                break;
            case 3:
                menuQueue(queue);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                pause();
        }
    } while (choice != 4);

    // Destroi as estruturas antes de sair
    destroyList(&list);
    destroyStack(&stack);
    destroyQueue(&queue);

    return 0;
}
