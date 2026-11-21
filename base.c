#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1; 
    return no;
}

int obterAltura(struct No* n) {
    if (n == NULL) {
        return 0; 
    }
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// FB = altura da esquerda - altura da direita
int obterFB(struct No* n) {
    if (n == NULL) {
        return 0;
    }
    return obterAltura(n->esq) - obterAltura(n->dir);
}

// imprime a arvore deitada, a direita fica em cima
void imprimirArvore(struct No* raiz, int espaco) {
    if (raiz == NULL)
        return;

    espaco += 10;

    imprimirArvore(raiz->dir, espaco);

    printf("\n");
    for (int i = 10; i < espaco; i++)
        printf(" ");

    int fb = obterFB(raiz);
    printf("[%d](fb:%d)\n", raiz->valor, fb);

    imprimirArvore(raiz->esq, espaco);
}
