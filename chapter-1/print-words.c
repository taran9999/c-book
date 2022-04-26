#include <stdio.h>

#define IN 1
#define OUT 0
#define SENTINEL 64

//Program for printing all words in input line by line. Word uses same definition as in count-words.c
main() {
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            printf("\n");
        } else if(state == OUT) {
            state == IN;
            printf("%c", c);
        }

        if(c == SENTINEL) {
            break;
        }
    }
}