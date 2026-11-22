#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static struct No* menorNo(struct No* no) {
    struct No* atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

struct No* remover(struct No* raiz, int chave) {
    if (raiz == NULL)
        return NULL;

    if (chave < raiz->valor) {
        raiz->esq = remover(raiz->esq, chave);
    } else if (chave > raiz->valor) {
        raiz->dir = remover(raiz->dir, chave);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            struct No* temp = (raiz->esq != NULL) ? raiz->esq : raiz->dir;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            struct No* sucessor = menorNo(raiz->dir);
            raiz->valor = sucessor->valor;
            raiz->dir = remover(raiz->dir, sucessor->valor);
        }
    }

    if (raiz == NULL)
        return NULL;

    raiz->altura = 1 + max(obterAltura(raiz->esq), obterAltura(raiz->dir));

    int fb = obterFB(raiz);

    if (fb > 1 && obterFB(raiz->esq) >= 0)
        return rotacionarDireita(raiz);

    if (fb > 1 && obterFB(raiz->esq) < 0) {
        raiz->esq = rotacionarEsquerda(raiz->esq);
        return rotacionarDireita(raiz);
    }

    if (fb < -1 && obterFB(raiz->dir) <= 0)
        return rotacionarEsquerda(raiz);

    if (fb < -1 && obterFB(raiz->dir) > 0) {
        raiz->dir = rotacionarDireita(raiz->dir);
        return rotacionarEsquerda(raiz);
    }

    return raiz;
}
