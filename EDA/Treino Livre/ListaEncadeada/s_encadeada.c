#include <stdio.h>
#include <stdlib.h>

typedef struct node no;
typedef int Item;

typedef struct head cabeca;
struct head{
    int num_itens;
    no *prox;
    no *ultimo;
};

struct node {
    Item info;
    no *prox;
};

//prototipo de funções
cabeca *criar_lista();
no *criar_no(Item);
int vazia(cabeca *);
int tamanho(cabeca*);

void inserir_depois ( cabeca * , no *, no *) ;
void inserir_inicio ( cabeca * , no *) ;
void inserir_fim ( cabeca *, no *) ;

void remover_inicio ( cabeca *) ;
void remover_fim ( cabeca *) ;
void remover_no ( cabeca *, no *) ;
no *buscar ( cabeca *, Item ) ;

int quantidade_celulas(cabeca *lista);
cabeca concatenacao(cabeca *, cabeca *);
void inserir_apos_k(cabeca *, int k, no *elem);
void swap(cabeca *lista, no *elem_x, no *elem_y);


//funções básicas
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

int vazia(cabeca *lista){
    return (lista->prox==NULL);
}

no *buscar(cabeca *lista, Item x){
    no *a = NULL;
    for(a= lista->prox; a && a->info!=x; a=a->prox);
    return a;
}
void inserir_inicio(cabeca *lista, no *elem){
    elem -> prox = lista -> prox ;
    lista -> prox = elem ;
// metadados
lista -> num_itens ++;
if( elem -> prox == NULL ) lista -> ultimo = elem ;
}

void inserir_depois(cabeca *lista, no*ref, no *elem){
    elem ->prox = ref->prox;
    ref->prox = elem;
    lista->num_itens++;

    if(elem->prox==NULL) lista->ultimo = elem;
}

void inserir_fim (cabeca *lista, no *elem){
    if(vazia(lista)) lista->prox = elem;
    else lista->ultimo->prox = elem;
    lista->ultimo = elem;
    elem->prox = NULL;
}

void remover_inicio(cabeca *lista){
    if (vazia(lista)) return;

    no *lixo = lista->prox;
    lista->prox = lixo->prox;

    lista->num_itens--;
    if (vazia(lista)) lista->ultimo = NULL;    
}

void remover_no(cabeca *lista, no *lixo){
    if (lista->prox == lixo) remover_inicio(lista);

    no *ant = NULL;
    for(ant = lista->prox; ant != NULL && ant->prox != lixo; ant = ant->prox);
    if(ant){
        ant->prox = lixo->prox;
        lista->num_itens--;
        if (ant->prox == NULL) lista->ultimo = ant;
    }
}
void remover_fim(cabeca *lista){
    if(vazia(lista)) return;

    no *lixo = lista->ultimo;
    no *ant = NULL;

    for(ant = lista->prox; ant != NULL && ant->prox != lixo; ant = ant->prox);
    if (ant){
        ant ->prox = NULL;
        lista->num_itens--;
        lista->ultimo = ant;
    }
}

int quantidade_celulas(cabeca *lista){
    int a;
    no *ant = NULL;
    for (ant = lista->prox; ant != NULL && ant->prox!=lista->ultimo; ant = ant->prox) a++;
    return a;
}

cabeca concatenacao(cabeca *lista1, cabeca *lista2){
    lista1->num_itens = lista1->num_itens+lista2->num_itens;

    lista1->ultimo->prox = lista2->prox;
    lista1->ultimo = lista2->ultimo;
    lista2->prox = NULL;
    lista2->ultimo = NULL;
    return *lista1;
}

void inserir_apos_k(cabeca *lista, int k, no *elem){
    no *ant = NULL;
    int a = 0;

    for (ant = lista->prox; ant!=NULL && ant->prox != lista->ultimo && a != k; ant = ant->prox)a++; 
    elem->prox = ant->prox;
    ant->prox = elem;

    lista->num_itens++;
}

void swap(cabeca *lista, no *elem_x, no *elem_y){
    no *aux = NULL;
    aux->prox = elem_y->prox;
    elem_y->prox = elem_x->prox;
    elem_x->prox = aux->prox;
    if(elem_x->prox == NULL) lista->ultimo = elem_x;
    else if(elem_y->prox == NULL) lista->ultimo = elem_y;

    aux->prox = NULL;
    free(aux);
}
