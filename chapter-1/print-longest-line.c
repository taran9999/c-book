#include <stdio.h>
#define MAXLINE 1000 //max input size

int getline(char line[], int maxline);
void copy(char to[], char from[]);

//Prints longest line
main() {
    int currentLength;
    int maxLength;
    char current[MAXLINE];
    char longest[MAXLINE];

    maxLength = 0;
    while(currentLength = getline(current, MAXLINE) > 0) {
        if(currentLength > maxLength) {
            maxLength = currentLength;
            copy(longest, current);
        }
    }

    if(maxLength > 0) {
        printf("longest: %s", longest);
    }

}

//Read line into line[] and return its length
int getline(char line[], int maxLine) {
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if(c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0'; //'\0' is the null character, strings are stored as character arrays with null at the end for termination
    return i;
}

//Copy from[] into to[]
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0') { //Sets them equal and checks for null to terminate loop
        i++;
    }
}