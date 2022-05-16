#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[4] = {'c', 'a', 't', '\0'};
    char s2[6] = {'b', 'r', 'e', 'a', 'k', '\0'};
    char s3[3] = {'z', 'z', '\0'};

    int a = any(s1, s2); // 1
    int b = any(s2, s1); // 3
    int c = any(s1, s3); // -1

    printf("s1/s2: %d, s2/s1: %d, s1/s3: %d\n", a, b, c);
}

//returns first index where any character in s2 appears in s1
int any(char s1[], char s2[]) {
    int index = -1;
    int found = 0;
    int i = 0;
    while(found == 0 && s1[i + 1] != '\0') {
        for(int j = 0; s2[j + 1] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                found = 1;
                index = i;
                break;
            }
        }
        i++;
    }
    return index;
}