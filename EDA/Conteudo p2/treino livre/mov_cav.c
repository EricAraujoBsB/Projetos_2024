#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

typedef struct {
    int x, y;
} Posicao;

int dentro_limites(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int bfs(Posicao inicio, Posicao fim) {
    if (inicio.x == fim.x && inicio.y == fim.y) return 0; 

    int visitado[SIZE][SIZE] = {0};
    Posicao fila[SIZE * SIZE];
    int inicio_fila = 0, fim_fila = 0;

    fila[fim_fila++] = inicio;
    visitado[inicio.x][inicio.y] = 1;

    int movimentos = 0;

    while (inicio_fila < fim_fila) {
        int tamanho_nivel = fim_fila - inicio_fila;
        movimentos++;

        for (int i = 0; i < tamanho_nivel; i++) {
            Posicao atual = fila[inicio_fila++];

            for (int j = 0; j < 8; j++) {
                int nx = atual.x + dx[j];
                int ny = atual.y + dy[j];

                if (dentro_limites(nx, ny) && !visitado[nx][ny]) {
                    if (nx == fim.x && ny == fim.y) return movimentos;

                    visitado[nx][ny] = 1;
                    fila[fim_fila++] = (Posicao){nx, ny};
                }
            }
        }
    }

    return -1; 
}

Posicao converte_notacao(char *pos) {
    return (Posicao){pos[0] - 'a', pos[1] - '1'};
}

int main() {
    char origem[3], destino[3];

    while (scanf("%s %s", origem, destino) != EOF) {
        Posicao inicio = converte_notacao(origem);
        Posicao fim = converte_notacao(destino);

        int movimentos = bfs(inicio, fim);

        printf("To get from %s to %s takes %d knight moves.\n", origem, destino, movimentos);
    }

    return 0;
}
