#include <stdio.h>
#include "avl.h"

int main() {
    struct No* raiz = NULL;

    int valores[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        printf("\nInserindo: %d...", valores[i]);
        raiz = inserir(raiz, valores[i]);
    }

    printf("\n\n--- ESTRUTURA DA ARVORE AVL (DEITADA) ---\n");
    imprimirArvore(raiz, 0);
    printf("\n-----------------------------------------\n");

    return 0;
}
