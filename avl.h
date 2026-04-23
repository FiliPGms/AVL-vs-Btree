#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct No* AVLtree;

int maior(int x, int y);
int fatorBalanceamento(struct No* no);
int alturaNo(struct No* no);
void rotacaoLL(AVLtree* no);
void rotacaoRR(AVLtree* no);
void rotacaoLR(AVLtree* no);
void rotacaoRL(AVLtree* raiz);
int inserir(AVLtree* raiz, int info);
void liberar_avl(AVLtree raiz);

#endif