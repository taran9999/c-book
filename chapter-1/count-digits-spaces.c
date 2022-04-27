#include <stdio.h>

#define SENTINEL 64

//Program that counts number of occurences of each digit, blank + tab + newline, and all other characters
main() {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for(i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9') {
            ++ndigit[c-'0']; //c - '0' changes this into an integer, provides the numeric value of the digit
        } else if(c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }

        if(c == SENTINEL) {
            break;
        }
    }

    printf("digits =");
    for(i = 0; i < 10; i++) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}