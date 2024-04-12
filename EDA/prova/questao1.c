#include <stdio.h>

void funcao(){
    int x;
    char str[101];
    scanf("%d", &x);
    if(x==1){
        // printf("entre com str\n");
        scanf("%[^\n]", str);
        // printf("%s", str);
        funcao();
        printf("%s\n", str);
        funcao();
    }
}

int main(){
    funcao();

    return 0;
}
