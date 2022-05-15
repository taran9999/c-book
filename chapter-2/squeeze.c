#include <stdio.h>

void squeeze(char s1[], char s2[]);

//removes chars from s1 that appear at the same spot in s2
int main() {
    char s1[4] = {'c', 'a', 't', '\0'};
    char s2[4] = {'b', 'a', 'g', '\0'};
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
    int i;
    int j;
    for(i = j = 0; s1[i] != '\0'; i++) {
        if(s1[i] != s2[i]) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}