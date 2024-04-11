#include <stdio.h>

void funcao(){
    int x;
    char str[101];
    scanf("%d", &x);
    if(x==1){
        printf("entre com str\n");
        scanf("%[^\n]", str);
        printf("esta aqui 1");
        funcao();
        printf("%s", str);
        funcao;
    }
}

int main(){
    funcao();

    return 0;
}
