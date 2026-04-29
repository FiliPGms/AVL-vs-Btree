#ifndef AVL_H
#define AVL_H

typedef struct No* AVLtree;

typedef enum {
    ROT_LL = 0,
    ROT_RR,
    ROT_LR,
    ROT_RL,
    QTD_ROT_TIPOS
} TipoRotacao;

typedef struct {
    int contagem[QTD_ROT_TIPOS];
    double tempo_total_rotacoes;
} EstatisticasAVL;

extern EstatisticasAVL stats;

void reset_stats();
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
