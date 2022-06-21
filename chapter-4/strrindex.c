#include <stdio.h>

int strrindex(char s[], char t[]);

int main() {
    char a[] = "abcabcabc";
    char b[] = "abc";
    char c[] = "abcde";
    char d[] = "xyz";
    char e[] = "d";
    char f[] = "";

    printf("strrindex(%s, %s): expected: %d; result: %d\n", a, b, 6, strrindex(a, b));
    printf("strrindex(%s, %s): expected: %d; result: %d\n", c, d, -1, strrindex(c, d));
    printf("strrindex(%s, %s): expected: %d; result: %d\n", c, e, 3, strrindex(c, e));
    printf("strrindex(%s, %s): expected: %d; result: %d\n", b, c, -1, strrindex(b, c));
    printf("strrindex(%s, %s): expected: %d; result: %d\n", a, f, -1, strrindex(a, f));
}

//Return the index of the rightmost occurence of t in s
int strrindex(char s[], char t[]) {
    int i, j, k;
    int index = -1;
    for(i = 0; s[i] != '\0'; i++) {
        for(k = i, j = 0; t[j] != '\0' && s[k] == t[j]; j++, k++);
        if(t[j] == '\0' && j > 0) {
            index = i;
        }
    }
    return index;
}