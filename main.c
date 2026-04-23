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
    printf(" Inicio com %d elementos\n", n);

    int* elementos = (int*)malloc(n * sizeof(int));
    if (elementos == NULL) {
        printf("Memoria insuficiente para %d elementos.\n", n);
        return;
    }

    double tempos_avl[ITERACOES];
    double tempos_bst[ITERACOES];

    for (int i = 0; i < ITERACOES; i++) {
        for (int j = 0; j < n; j++) {
            elementos[j] = gerar_random();
        }

        //árvoreAVL
        AVLtree avl = NULL;
        clock_t inicio = clock();
        for (int j = 0; j < n; j++) {
            inserir(&avl, elementos[j]);
        }
        clock_t fim = clock();
        tempos_avl[i] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        liberar_avl(avl);

        //arvoreB
        BSTree bst = NULL;
        inicio = clock();
        for (int j = 0; j < n; j++) {
            bst = inserir_bst(bst, elementos[j]);
        }
        fim = clock();
        tempos_bst[i] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        liberar_bst(bst);

        printf("iteracao %d: AVL = %7.3fs | BT = %7.3fs\n", i + 1, tempos_avl[i], tempos_bst[i]);
    }

    printf("\nResultados Consolidados (medias)\n");
    double soma_avl = 0, soma_bst = 0;
    for(int i=0; i<ITERACOES; i++) {
        soma_avl += tempos_avl[i];
        soma_bst += tempos_bst[i];
    }
    printf("Media AVL: %.4fs\n", soma_avl / ITERACOES);
    printf("Media BT: %.4fs\n", soma_bst / ITERACOES);

    free(elementos);
}

int main() {
    srand(42);

    realizar_teste(1000000);
    realizar_teste(5000000); 

    return 0;
}
