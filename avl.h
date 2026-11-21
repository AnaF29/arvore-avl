#ifndef AVL_H
#define AVL_H

struct No {
    int valor;
    struct No *esq, *dir;
    int altura;
};

struct No* novoNo(int valor);
int obterAltura(struct No* n);
int max(int a, int b);
int obterFB(struct No* n);
void imprimirArvore(struct No* raiz, int espaco);

struct No* rotacionarDireita(struct No* y);
struct No* rotacionarEsquerda(struct No* x);

struct No* inserir(struct No* no, int valor);

struct No* remover(struct No* raiz, int chave);

#endif
