#include <stdio.h>

long int seq[81];

long int fibonacci(int n) {
    
    if (n <= 1) return n;
    
    if (seq[n] != 0) {
        return seq[n];
    }

    seq[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return seq[n];
}
