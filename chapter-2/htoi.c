#include <stdio.h>
#include <ctype.h>
#include <math.h> //to compile: gcc htoi.c -lm

int htoi(char s[]);

int main() {
    char a[2] = {'E', '\0'}; //14
    char b[4] = {'1', '2', 'F', '\0'}; //303
    char c[3] = {'9', 'B', '\0'}; //155

    printf("%d, %d, %d\n", htoi(a), htoi(b), htoi(c));
}

int htoi(char s[]) {
    double n = 0;
    int i = 0;
    int len;
    for(len = 0; s[len] != '\0'; len++);
    while(i < len) {
        if(isdigit(s[i])) {
            n += (pow(16, len - 1 - i) * (s[i] - '0'));
        } else {
            if(s[i] == 'A' || s[i] == 'a') {
                n += (pow(16, len - 1 - i) * 10);
            }

            if(s[i] == 'B' || s[i] == 'b') {
                n += (pow(16, len - 1 - i) * 11);
            }

            if(s[i] == 'C' || s[i] == 'c') {
                n += (pow(16, len - 1 - i) * 12);
            }

            if(s[i] == 'D' || s[i] == 'd') {
                n += (pow(16, len - 1 - i) * 13);
            }

            if(s[i] == 'E' || s[i] == 'e') {
                n += (pow(16, len - 1 - i) * 14);
            }

            if(s[i] == 'F' || s[i] == 'f') {
                n += (pow(16, len - 1 - i) * 15);
            }
        }
        i++;
    }
    return (int)n;
}