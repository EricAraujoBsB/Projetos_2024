#include <stdio.h>

int main(){
    printf("insira os valores dos jogadores A, B e C\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b==c){
        printf("empate");

    }
    else if(a != b && b==c){
        printf("o vencedor foi A");
    }
    else if(a != b && a==c){
        printf("o vencedor foi B");
    }
    else if(c != b && b==a){
        printf("o vencedor foi C");
    }
    return 0;
}
