#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct{
    Item *item;
    int primeiro, ultimo;
} Fila;


Fila *create(Item maxN);
void enqueue(Fila *f, Item y);
Item dequeue(Fila *f);
int vazia(Fila *f);
void print(Fila *f);



Fila *create(Item maxN){
    Fila *p = malloc(sizeof(Fila));
    p->item = malloc(maxN * sizeof(Item));
    p->primeiro = p->ultimo = 0;
    return p;
}

void enqueue(Fila *f, Item y){
    f->item[f->ultimo++] = y;
}

Item dequeue(Fila *f){
    return f->item[f->primeiro++];
}

int vazia(Fila *f){
    return f->primeiro == f->ultimo;
}

void print(Fila *f){
    printf("\n FILA p=%d e u%d\n", f->primeiro, f->ultimo);
    for(int i = f->primeiro; i < f->ultimo; i++) printf("F[%d] | ", i);
    printf("\n");

    for(int i = f->primeiro; i < f->ultimo; i++) printf("%3d | ", f->item[i]);
    printf("\n");
}

int main(){
    printf("\n \n Criando a fila e enfileirando 10 elementos\n");
    Item N = 100;
    Fila *fila1 = create(N);
    for(int i=0; i < 10; i++) enqueue(fila1, i);
    print(fila1);

    printf("\n\n Desenfileirando os 3 primeiros elementos\n");
    for(int i=fila1->primeiro; i < 3; i++) dequeue(fila1);
    print(fila1);

    return 0;  
}

