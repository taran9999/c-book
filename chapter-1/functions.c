#include <stdio.h>

int power(int, int); //declares function, prevents "implicit declaration of function." Called "function prototype."git 

main() {
    printf("%d\n", power(2, 5));
}

int power(int base, int n) { //equivalent to pow(x, y) function in standard library
    int i, p;

    p = 1;
    for(i = 1; i <= n; i++) {
        p *= base;
    }
    return p;
}

// return-type function-name(parameters if any)