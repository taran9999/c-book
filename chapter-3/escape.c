#include <stdio.h>

void escape(char s[], char t[]);
void reverseEscape(char s[], char t[]);

int main() {
    char s[7] = {'a', 'b', '\n', 'c', '\t', 'd', '\0'};
    char t[9];
    escape(s, t);
    printf("escape\ns: %s\nt: %s\n", s, t);
    reverseEscape(t, s);
    printf("reverseEscape\ns: %s\nt: %s\n", s, t);
}

//convert newlines and tabs to visible escape characters while copying s to t
void escape(char s[], char t[]) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;

            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;

            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

void reverseEscape(char s[], char t[]) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        if(s[i] == '\\') {
            switch(s[++i]) {
                case 'n':
                    t[j++] = '\n';
                    break;

                case 't':
                    t[j++] = '\t';
                    break;

                default:
                    t[j++] = '\\';
                    t[j++] = s[i];
                    break;
            }
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}