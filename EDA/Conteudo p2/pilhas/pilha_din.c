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
void push(cabeca *lista, Item x);
Item pop(cabeca *lista);
Item peek(cabeca *lista);
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

void push(cabeca *lista, Item x){
    no *novo = criar_no(x);
    if(novo){
        if(vazia(lista)) lista->ultimo = novo;
        novo->prox = lista->prox;
        lista->prox = novo;

        lista->num_itens++;
    }
}

Item pop(cabeca *lista){
    no *topo = lista->prox;
    lista->prox = topo->prox;

    if (topo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = topo->info;
    free(topo);
    return x;
}

Item peek(cabeca *lista){
    return(lista->prox->info);
}

int vazia(cabeca *lista){
    lista->ultimo = NULL;
    return lista->num_itens = 0;
}
