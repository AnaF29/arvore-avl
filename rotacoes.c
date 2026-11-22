#include "avl.h"

// Rotacao simples a direita (LL) - desequilibrio na "esquerda da esquerda" 
struct No* rotacionarDireita(struct No* y) {
    struct No* x = y->esq;
    struct No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(obterAltura(y->esq), obterAltura(y->dir)) + 1;
    x->altura = max(obterAltura(x->esq), obterAltura(x->dir)) + 1;

    return x;
}

// Rotacao simples a esquerda (RR) - desequilibrio na "direita da direita" 
struct No* rotacionarEsquerda(struct No* x) {
    struct No* y = x->dir;
    struct No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(obterAltura(x->esq), obterAltura(x->dir)) + 1;
    y->altura = max(obterAltura(y->esq), obterAltura(y->dir)) + 1;

    return y;
}