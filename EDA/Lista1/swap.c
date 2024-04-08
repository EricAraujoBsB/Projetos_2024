#include <stdio.h>


void swap(int *p, int *q){
    int x;
    int *p3 = &x;

    *p3 = *p;
    *p = *q;
    *q = *p3;

}

