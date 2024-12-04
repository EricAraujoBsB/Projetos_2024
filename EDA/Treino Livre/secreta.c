#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t numero;
    int byte;
    char caractere;
    int i;

    // Imprime os caracteres da mensagem em uma única linha
    while (scanf("%x", &numero) != EOF) {
        for (i = 0; i < 4; i++) {
            byte = (numero >> (i * 8)) & 0xFF; // Extrai o byte correspondente
            if (byte == 0) {                  // Verifica o EOS (End of String)
                printf("\n");
                return 0;
            }
            caractere = (char)byte;           // Converte o byte para caractere
            printf("%c", caractere);          // Imprime o caractere
        }
    }

    printf("\n"); // Nova linha no final
    return 0;
}
