#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct {
    Item *item;
    int topo;
}Pilha;



Pilha *create(int N);
int vazia(Pilha *p);
void push(Pilha *p, Item item);
Item pop(Pilha *p);
Item peek(Pilha *p);

Pilha *create(int N){
    Pilha *p = malloc(sizeof(Pilha));
    p->item = malloc(N * sizeof(Item));
    p->topo = 0;
    return p;
}

void push(Pilha *p, Item item){
    p->item[p->topo++] = item;
}

Item pop(Pilha *p){
    return p->item[--p->topo];
}

Item peek(Pilha *p){
    return p->item[p->topo-1];
}

int vazia(Pilha *p){
    return p->topo == 0;
}


