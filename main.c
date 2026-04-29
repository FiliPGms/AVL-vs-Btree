#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "bTree.h"

#define ITERACOES 10

int gerar_random() {
    return (rand() << 15) ^ rand();
}

void realizar_teste(int n) {
    printf("iniciando com %d elementos\n", n);

    int* elementos = (int*)malloc(n * sizeof(int));
    if (elementos == NULL) {
        printf("Erro: Memoria insuficiente.\n");
        return;
    }

    for (int i = 0; i < ITERACOES; i++) {
        for (int j = 0; j < n; j++) elementos[j] = gerar_random();

        // Teste avl
        reset_stats();
        AVLtree avl = NULL;
        clock_t inicio_avl = clock();
        for (int j = 0; j < n; j++) inserir(&avl, elementos[j]);
        clock_t fim_avl = clock();
        
        int h_avl = alturaNo(avl);
        double tempo_avl = (double)(fim_avl - inicio_avl) / CLOCKS_PER_SEC;
        
        int total_rot = 0;
        for(int r = 0; r < QTD_ROT_TIPOS; r++) total_rot += stats.contagem[r];

        //Teste bst
        BSTree bst = NULL;
        clock_t inicio_bst = clock();
        for (int j = 0; j < n; j++) bst = inserir_bst(bst, elementos[j]);
        clock_t fim_bst = clock();
        
        int h_bst = altura_bst(bst);
        double tempo_bst = (double)(fim_bst - inicio_bst) / CLOCKS_PER_SEC;

        printf("teste %02d:\n", i + 1);
        printf("  AVL: Tempo=%.3fs, Altura=%d, Rotacoes=%d (LL:%d, RR:%d, LR:%d, RL:%d), Tempo Rot: %.6fs\n", 
               tempo_avl, h_avl, total_rot, 
               stats.contagem[ROT_LL], stats.contagem[ROT_RR], 
               stats.contagem[ROT_LR], stats.contagem[ROT_RL], 
               stats.tempo_total_rotacoes);
        printf("  BST: Tempo=%.3fs, Altura=%d\n", tempo_bst, h_bst);

        liberar_avl(avl);
        liberar_bst(bst);
    }

    free(elementos);
}

int main() {
    srand(42);
    realizar_teste(1000000);
    realizar_teste(5000000); 
    return 0;
}
