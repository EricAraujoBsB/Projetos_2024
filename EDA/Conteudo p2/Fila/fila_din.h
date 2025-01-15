#ifndef FILA_DIN_H
#define FILA_DIN_H

#include <stdio.h>
#include <stdlib.h>

//definicoes
typedef struct node no;
typedef int Item;
typedef struct head cabeca;

typedef struct head{
    int num_itens;
    no *prox;
    no *ultimo;
};

struct node {
    Item info;
    no *prox;
};


//prototipo de funcoes
cabeca *criar_lista();
no *criar_no(Item x);
void enqueue(cabeca *lista, Item x);
Item dequeue(cabeca *lista);
int vazia(cabeca *lista);


//declaracao de funcoes
cabeca *criar_lista(){
    cabeca *le = malloc(sizeof(cabeca));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;

    return le;
}

no *criar_no(Item x){
    no *novo = malloc(sizeof(no));
    novo->prox = NULL;
    novo->info = x;
    return novo;
}

void enqueue(cabeca *lista, Item x){
    no *novo = criar_no(x);
    if(novo){
        if(vazia(lista)) lista->prox = novo;
        else lista->ultimo->prox = novo;

        lista->ultimo = novo;
        novo->prox = NULL;

        lista->num_itens++;   
    }
}

Item dequeue(cabeca *lista){
    no *lixo = lista->prox;
    lista->prox = lixo->prox;

    if(vazia(lista)) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info;
    free(lixo);

    return x;
}

int vazia(cabeca *lista){
    return (lista->prox==NULL);

}

#endif