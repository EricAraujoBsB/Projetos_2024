#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

#define key(A) A
#define less(A, B) (key(A)<key(B))
#define exch(A, B) {Item t = A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)

static Item *pq;
static int N;

//prototipo de funcoes
void show(int v[], int l, int r);
int is_sorted(int v[], int l, int r);
void PQinit(int maxN);
int PQempty();
void fixUp(int k);
void fixDown(int k);
void PQinsert(Item v);
Item PQdelmax();
void PQsort(Item *v, int l, int r);
void heap_sort(Item *v, int l, int r);


void show(int v[], int l, int r){
    for(int i = l; i<=r; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int is_sorted(int v[], int l, int r){
    int p;
    for(p=r; p>l && v[p-1] <= v[p]; p--);

    return (p==0);
}

void PQinit (int maxN){
    pq = malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

int PQempty(){
    return N==0;
}

void fixUp(int k){
    while(k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
}

void fixDown(int k, int N){
    int j;

    while(2*k <= N){
        j = 2*k;
        //troca maior filho
        if(j<N && less(pq[j], pq[j+1])) j++;

        //se pk[k] nao precisar descer, pare
        if(!less(pq[k], pq[j])) break;

        //senao afunde
        exch(pq[k], pq[j]);
        k=j;
    }
}



