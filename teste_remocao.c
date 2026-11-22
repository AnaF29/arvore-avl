#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static int verificar(struct No* n, int min, int max_) {
    if (n == NULL) return 0;
    if (n->valor <= min || n->valor >= max_) return -1;
    int he = verificar(n->esq, min, n->valor);
    int hd = verificar(n->dir, n->valor, max_);
    if (he < 0 || hd < 0) return -1;
    if (he - hd > 1 || hd - he > 1) return -1;
    int h = 1 + (he > hd ? he : hd);
    if (h != n->altura) return -1;
    return h;
}

static void liberar(struct No* n) {
    if (n == NULL) return;
    liberar(n->esq);
    liberar(n->dir);
    free(n);
}

static struct No* montar(int v[], int n) {
    struct No* r = NULL;
    for (int i = 0; i < n; i++) r = inserir(r, v[i]);
    return r;
}

static void resultado(const char* nome, struct No* r) {
    printf("[%s] %s\n", verificar(r, -1000000, 1000000) >= 0 ? "OK" : "FALHOU", nome);
}

int main() {
    struct No* r;

    int a[] = {20, 10, 30};
    r = montar(a, 3);
    r = remover(r, 10);
    resultado("remover folha", r);
    liberar(r);

    int b[] = {20, 10, 30, 5};
    r = montar(b, 4);
    r = remover(r, 10);
    resultado("remover nó com um filho", r);
    liberar(r);

    int c[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};
    r = montar(c, 11);
    r = remover(r, 50);
    resultado("remover raiz com dois filhos", r);
    printf("Raiz agora: %d (esperado: 54, sucessor de 50)\n", r->valor);
    liberar(r);

    int d[] = {5, 3, 8, 2, 4};
    r = montar(d, 5);
    r = remover(r, 8);
    resultado("remoção com FB do filho = 0 (rotação simples)", r);
    liberar(r);

    int e[] = {20, 10, 30, 15};
    r = montar(e, 4);
    r = remover(r, 30);
    resultado("remoção causando LR", r);
    liberar(r);

    int f[] = {20, 10, 30, 25};
    r = montar(f, 4);
    r = remover(r, 10);
    resultado("remoção causando RL", r);
    liberar(r);

    int g[] = {8, 5, 11, 3, 7, 10, 12, 2, 4, 6, 9, 1};
    r = montar(g, 12);
    printf("\n--- ANTES de remover 12 ---\n");
    imprimirArvore(r, 0);
    r = remover(r, 12);
    printf("\n--- DEPOIS de remover 12 (duas rotações em cascata) ---\n");
    imprimirArvore(r, 0);
    resultado("remoção com rotações em cascata", r);
    printf("Raiz agora: %d (esperado: 5)\n", r->valor);
    liberar(r);

    r = montar(a, 3);
    r = remover(r, 999);
    resultado("remover chave inexistente", r);
    liberar(r);

    return 0;
}
