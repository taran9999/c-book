/* Program for copying user input one character at a time.
Pseudocode:
read character
while(the character is not the end of file indicator)
    output the last character read
    read character
*/

#include <stdio.h>
main() {
    /*1st version
    int c;
    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
    */
   //2nd version, written more concisely
   int c;
   while((c = getchar()) != EOF) {
       putchar(c);
   }
}

/*
- Any integer type can be used for storing chars. In this case, it is stored as int instead of char because char does not have space to hold the value of EOF.
    - int has space to hold EOF as well as any value of getchar()
- EOF is the end of file character, which is an integer included in stdio.h.
- getchar() reads the next input character from a text stream and returns that value.
- putchar(c) prints the integer value c as a character.
*/