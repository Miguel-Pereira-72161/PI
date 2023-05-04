#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// 1.
int length (LInt l) {

    int len = 0;
    struct lligada *current = l;

    while (l != NULL) {
        len++;
        current = current->prox;
    }
    return len;
}

// 2.
void freeLinkedList (LInt l) {

    struct lligada *current = l;
    struct lligada *prox = NULL;

    while (l != NULL) {
        prox = current->prox;
        free(current);
        current = prox;
    }
}

// 3.
void printLinkedList (LInt k) {

    struct lligada *current = l;

    while (l != NULL) {
        printf("%d\n", current->valor);
        current = current->prox;
    }
}

// 4.

LInt reverseL (LInt l) {
    struct lligada *current = l;
    struct lligada *next = NULL;
    struct lligada *previous = NULL;

    while (current != NULL) {
        next = current->prox;
        current->prox = previous;
        previous = current;
        current = next;
    }
    
    current = previous;

    return current;
}

// 5.

void insertOrd (LInt *l, int x) {

    struct lligada *newNode = malloc(sizeof (struct lligada));
    newNode->valor = x;
    newNode->prox = NULL;
    
    struct lligada *current = *l;

    if (*l == NULL || (*l)->valor >= x) {
        newNode->prox = *l;
        *l = newNode;
    }
    
    else { 
    while (current->prox != NULL && current->prox->valor < x) {
        current = current->prox;
    }
    newNode->prox = current->prox;
    current->prox = newNode;
    }
}
