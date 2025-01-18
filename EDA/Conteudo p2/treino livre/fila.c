#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    // Aloca memória para o novo nó
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) {
        // Retorna NULL em caso de falha na alocação de memória
        return NULL;
    }
    
    // Inicializa o novo nó
    novo->dado = x;
    novo->prox = NULL;
    
    if (f == NULL) {
        // Se a fila está vazia, o novo nó é o primeiro elemento
        return novo;
    }
    
    // Encontra o último nó da fila
    celula *atual = f;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    // Conecta o novo nó ao final da fila
    atual->prox = novo;
    
    // Retorna o ponteiro para a cabeça da fila
    return f;
}
