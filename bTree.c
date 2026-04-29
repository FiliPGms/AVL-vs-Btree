#include <stdlib.h>
#include <stdio.h>
#include "bTree.h"

struct bTree {
    int dado;
    struct bTree* esquerda;
    struct bTree* direita;
};

BSTree inserir_bst(BSTree raiz, int valor) {
    if (raiz == NULL) {
        struct bTree* novo = (struct bTree*)malloc(sizeof(struct bTree));
        if (novo == NULL) return NULL;
        novo->dado = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir_bst(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir_bst(raiz->direita, valor);
    }
    return raiz;
}

void liberar_bst(BSTree arvore) {
    if (arvore != NULL) {
        liberar_bst(arvore->esquerda);
        liberar_bst(arvore->direita);
        free(arvore);
    }
}

int altura_bst(BSTree raiz) {
    if (raiz == NULL) return -1;
    int alt_esq = altura_bst(raiz->esquerda);
    int alt_dir = altura_bst(raiz->direita);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}
