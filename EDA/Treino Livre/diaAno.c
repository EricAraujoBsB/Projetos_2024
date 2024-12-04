#include <stdio.h>
#include <stdbool.h>

// Subprograma que verifica se o ano é bissexto
void verificaBissexto(int *ano, bool *bissexto) {
    *bissexto = (*ano % 400 == 0) || (*ano % 4 == 0 && *ano % 100 != 0);
}

// Subprograma que valida se a entrada é válida
void validaEntrada(int *diaDoAno, int *ano, bool *valida) {
    bool bissexto;
    verificaBissexto(ano, &bissexto);

    int totalDias = bissexto ? 366 : 365;

    if (*diaDoAno >= 1 && *diaDoAno <= totalDias) {
        *valida = true;
    } else {
        *valida = false;
    }
}

// Subprograma que calcula o mês e o dia a partir do dia do ano
void calculaDiaMes(int *diaDoAno, int *ano, int *dia, int *mes) {
    int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool bissexto;

    // Ajustar para ano bissexto
    verificaBissexto(ano, &bissexto);
    if (bissexto) {
        diasNoMes[1] = 29;
    }

    // Calcular mês e dia
    *mes = 0;
    while (*diaDoAno > diasNoMes[*mes]) {
        *diaDoAno -= diasNoMes[*mes];
        (*mes)++;
    }
    *dia = *diaDoAno;
    (*mes)++; // Ajustar para formato de 1 a 12
}

// Função principal
int main() {
    int diaDoAno, ano, dia, mes;
    bool valida;

    // Entrada
    printf("Digite o dia do ano e o ano (d a): ");
    scanf("%d %d", &diaDoAno, &ano);

    // Validação
    validaEntrada(&diaDoAno, &ano, &valida);

    if (!valida) {
        printf("Entrada inválida.\n");
        return 1;
    }

    // Cálculo da data
    calculaDiaMes(&diaDoAno, &ano, &dia, &mes);

    // Saída
    printf("A data correspondente é: %02d/%02d/%d\n", dia, mes, ano);

    return 0;
}
