#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct No
{
    int altura;
    AVLtree* esquerda;
    AVLtree* direita;
    int dado;
};


int maior(int x, int y){
    if(x>y){
        return x;
    }

    return y;
}

int fatorBalanceamento(struct No* no){
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
        
    }

    struct No* atual = *raiz;
    if(info<atual->dado){
        if(res= inserir(&(atual->esquerda), info) == 1){
            if(fatorBalanceamento(atual)>=2){
                
            }
        }
    }
    
}