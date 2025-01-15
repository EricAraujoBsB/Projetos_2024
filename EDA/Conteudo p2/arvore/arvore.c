#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct node no;
struct node{
    Item item;
    no *pai;
    no *esq, *dir;
};

no *criar_arvore(Item x, no *p, no *e, no *d){
    no *raiz = malloc(sizeof(no));
    raiz->pai = p;
    raiz->esq = e;
    raiz->dir = d;
    raiz->item = x;

    return raiz;
}

no *avo(no *elemento){
    if((elemento != NULL) && (elemento->pai != NULL))
        return elemento->pai->pai;
    
    return NULL;
}

no *tio(no *elemento){
    no *vo = avo(elemento);
    if(vo == NULL) return NULL;

    if(elemento->pai == vo->esq)
        return vo->dir;
    
    return vo->dir;
}

no *irmao(no *elemento){
    if((elemento != NULL) && (elemento->pai != NULL)){
        if(elemento == elemento->pai->esq)
            return pai->dir;
        
        return pai->esq;
    }
}

no *busca_linear(no *elemento, Item v){
    if(elemento == NULL || elemento->item == v)
        return elemento;
    no *e = busca_linear(elemento->esq, v)
    if(e != NULL) return e;

    return busca_linear(elemento->dir, v);
}

int numero_nos(no *raiz){
    if(raiz== NULL) return 0;
    return 1 + numero_nos(raiz->esq) + numero_nos(raiz->dir);
}

int altura(no *raiz){
    if (raiz == NULL) return 0;

    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}
