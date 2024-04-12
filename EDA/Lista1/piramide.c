#include <stdio.h>

int main(){
    int n;
    int i = 0;

    scanf("%d", &n);

    while (i < n){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }

        for (int j = 0; j <= 2*i ; j++){
            printf("*");
        }
        
        printf("\n");
        i++;
    }
    return 0;
}
