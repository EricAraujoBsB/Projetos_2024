#include <stdio.h>


void regua (int n){
    if (n==0) return;
    else{
        regua (n-1);
        printf(".");
        for (int i = 0; i < n; i++){
            printf("-");
        }
        printf("\n");
        regua (n-1);
    }

}

int main(){
    int control;
    printf("insira o numero de itens desejados para a regua\n");
    scanf("%d", control);
    regua(control);
    return 0;
}
