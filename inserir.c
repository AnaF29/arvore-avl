#include <stdlib.h>
#include "avl.h"

struct No* inserir(struct No* no, int valor) {
    // Inserção BST normal
    if (no == NULL) {
        return novoNo(valor);
    }

    if (valor < no->valor) {
        no->esq = inserir(no->esq, valor);
    } else if (valor > no->valor) {
        no->dir = inserir(no->dir, valor);
    } else {
        return no; // valores duplicados não são permitidos
    }

    // Atualiza a altura do nó atual
    no->altura = 1 + max(obterAltura(no->esq), obterAltura(no->dir));

    // Calcula o fator de balanceamento
    int fb = obterFB(no);

    // 4 casos de desbalanceamento

    // LL: esquerda da esquerda -> rotação simples à direita
    if (fb > 1 && valor < no->esq->valor) {
        return rotacionarDireita(no);
    }

    // RR: direita da direita -> rotação simples à esquerda
    if (fb < -1 && valor > no->dir->valor) {
        return rotacionarEsquerda(no);
    }

    // LR: direita da esquerda -> rotação dupla
    if (fb > 1 && valor > no->esq->valor) {
        no->esq = rotacionarEsquerda(no->esq);
        return rotacionarDireita(no);
    }

    // RL: esquerda da direita -> rotação dupla
    if (fb < -1 && valor < no->dir->valor) {
        no->dir = rotacionarDireita(no->dir);
        return rotacionarEsquerda(no);
    }

    // Já estava balanceado
    return no;
}
