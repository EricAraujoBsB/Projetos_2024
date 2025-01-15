#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int *dados;
    int N, p, u;
}fila;

int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia
    if (f->u == f->N) {
        int novo_tamanho = f->N * 2;
        int *novo_dados = (int *)malloc(novo_tamanho * sizeof(int));
        if (!novo_dados) return 0; // Falha na alocação

        int i, j = 0;
        for (i = f->p; i != f->u; i = (i + 1) % f->N) {
            novo_dados[j++] = f->dados[i];
        }

        free(f->dados);
        f->dados = novo_dados;
        f->N = novo_tamanho;
        f->p = 0;
        f->u = j;
    }

    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;

    return 1; // Inserção bem-sucedida
}
