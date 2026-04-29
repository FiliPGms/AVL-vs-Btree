#ifndef BTREE_H
#define BTREE_H

typedef struct bTree* BSTree;

BSTree inserir_bst(BSTree raiz, int valor);
void liberar_bst(BSTree arvore);
int altura_bst(BSTree raiz);

#endif
