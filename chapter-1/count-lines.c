#include <stdio.h>

#define SENTINEL 64

//Program for counting number of lines in input
main() {
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n' ) {
            ++nl;
        }

        if(c == SENTINEL) {
            break;
        }
    }
    printf("%d\n", nl);
}