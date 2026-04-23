#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct No
{
    int altura;
    struct No* esquerda;
    struct No* direita;
    int dado;
};


int maior(int x, int y){
    if(x>y){
        return x;
    }

    return y;
}

int fatorBalanceamento(struct No* no){
    if (no == NULL) return 0;
    return labs(alturaNo(no->direita) - alturaNo(no->esquerda));
}

int alturaNo(struct No* no){
    if(no!=NULL){
        return no->altura;
    }

    return -1;
}

void rotacaoLL(AVLtree* no){
    struct No* b;
    b = (*no)->esquerda;
    (*no)->esquerda = b->direita;
    b->direita = *no;
    (*no)->altura = maior(alturaNo((*no)->esquerda), alturaNo((*no)->direita)) + 1;
    b->altura = maior(alturaNo(b->esquerda), (*no)->altura) + 1;
    *no = b;
}

void rotacaoRR(AVLtree* no){
    struct No* b;
    b = (*no)->direita;
    (*no)->direita = b->esquerda;
    b->esquerda = *no;
    (*no)->altura = maior(alturaNo((*no)->esquerda), alturaNo((*no)->direita)) + 1;
    b->altura = maior(alturaNo(b->direita), (*no)->altura) + 1;
    *no = b;
}

void rotacaoLR(AVLtree* no){
    rotacaoRR(&((*no)->esquerda));
    rotacaoLL(no);
}

void rotacaoRL(AVLtree* raiz){
    rotacaoLL(&((*raiz)->direita));
    rotacaoRR(raiz);
}

int inserir(AVLtree* raiz, int info){   
    int res;            
    if(*raiz==NULL){
        struct No* novoNo = (struct No*)malloc(sizeof(struct No));
        if(novoNo!=NULL){
            novoNo->dado = info;
            novoNo->direita = NULL;
            novoNo->esquerda = NULL;
            novoNo->altura = 0;
            *raiz = novoNo;
            return 1;
        }

        return 0;
        
    }

    struct No* atual = *raiz;
     if (info < atual->dado) {
        if ((res = inserir(&(atual->esquerda), info)) == 1) {
            if (fatorBalanceamento(atual) >= 2) {
                if (info < atual->esquerda->dado) {
                    rotacaoLL(raiz);
                } else {
                    rotacaoLR(raiz);
                }
            }
        }
    } else if (info > atual->dado) {
        if ((res = inserir(&(atual->direita), info)) == 1) {
            if (fatorBalanceamento(atual) >= 2) {
                if (info > atual->direita->dado) {
                    rotacaoRR(raiz);
                } else {
                    rotacaoRL(raiz);
                }
            }
        }
    } else {
        return 0; // duplicate
    }

    atual->altura = maior(alturaNo(atual->esquerda), alturaNo(atual->direita)) + 1;
    return res;
}

void liberar_avl(AVLtree raiz){
    if(raiz == NULL) return;
    liberar_avl(raiz->esquerda);
    liberar_avl(raiz->direita);
    free(raiz);
}
