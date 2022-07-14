#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char a[] = "abcde";
    char b[] = "cde";

    printf("strend(%s, %s) -> %d\n", a, b, strend(a, b));
    printf("strend(%s, %s) -> %d\n", b, a, strend(b, a));
}

//return 1 if string s ends with string t, 0 if it doesn't
int strend(char *s, char *t) {
    char *starts = s;
    char *startt = t;

    while(*s != '\0') s++;
    while(*t != '\0') t++;

    while(*s-- == *t-- && s != starts && t != startt);

    return (*s == *t && t == startt && *s != '\0');
}