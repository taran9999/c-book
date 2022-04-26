#include <stdio.h>

#define IN 1
#define OUT 0
#define SENTINEL 64

//Program for counting words (word is a sequence of characters that does not contain space, tab, or newline)
/*While the next character is not EOF, increment the number of characters. If the character is a newline, increment number of lines. 
If the character is blank, newline, or tab, set word state to OUT. If word state is OUT, set back to IN then increment number of words.*/
main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') {
            ++nl;
        }
        if(c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if(state == OUT) {
            state = IN;
            ++nw;
        }

        if(c == SENTINEL) {
            break;
        }
    }
    printf("chars: %d, lines: %d, words: %d\n", nc, nl, nw);
}