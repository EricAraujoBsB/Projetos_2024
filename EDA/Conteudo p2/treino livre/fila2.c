#include <stdlib.h>

typedef struct fila {
    int *dados; 
    int N;      
    int p;      
    int u;      
} fila;

int enfileira(fila *f, int x) {
    if (f->u >= f->N) {
        int novo_tamanho = f->N * 2;
        int *novo_dados = (int *)malloc(novo_tamanho * sizeof(int));
        if (!novo_dados) return 0;

        for (int i = f->p; i < f->u; i++) {
            novo_dados[i - f->p] = f->dados[i];
        }

        free(f->dados); 
        f->dados = novo_dados;
        f->N = novo_tamanho;
        f->u = f->u - f->p; 
        f->p = 0;         
    }

    f->dados[f->u] = x;
    f->u++;
    return 1; 
}
