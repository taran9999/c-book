#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
    char a[4] = {'a', '-', 'z', '\0'};
    char b[27];
    char c[5] = {'-', 'A', '-', 'Z', '\0'};
    char d[28];
    char e[10] = {'r', '6', '5', 'f', '0', '-', '9', '-', '5', '\0'};
    char f[17];

    expand(a, b);
    expand(c, d);
    expand(e, f);

    printf("%s -> %s\n", a, b);
    printf("%s -> %s\n", c, d);
    printf("%s -> %s\n", e, f);
}

//Expand shorthands a-z, A-Z, 0-9 into the full list (abc...xyz etc.) while copying s1 to s2
void expand(char s1[], char s2[]) {
    /*
    if s1[i] is not a, A, or 0: s2[j++] = s1[i]
    else check next two characters, and add the sequence
    */
   int i, j;
   for(i = j = 0; s1[i] != '\0'; i++) {
       switch (s1[i])
       {
        case 'a':
           if(s1[i + 1] == '-' && s1[i + 2] == 'z') {
               for(int c = 97; c <= 122; c++) {
                   s2[j++] = c;
               }
               i += 2;
           } else {
               s2[j++] = s1[i];
           }
           break;

        case 'A':
            if(s1[i + 1] == '-' && s1[i + 2] == 'Z') {
               for(int c = 65; c <= 90; c++) {
                   s2[j++] = c;
               }
               i += 2;
           } else {
               s2[j++] = s1[i];
           }
           break;

        case '0':
            if(s1[i + 1] == '-' && s1[i + 2] == '9') {
               for(int c = 48; c <= 57; c++) {
                   s2[j++] = c;
               }
               i += 2;
           } else {
               s2[j++] = s1[i];
           }
       
       default:
           s2[j++] = s1[i];
       }
    }

    s2[j] = '\0';
}