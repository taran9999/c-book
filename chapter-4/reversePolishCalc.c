#include <stdio.h>
#include <stdlib.h> //for atof()
#include <ctype.h> //used for getop
#include <math.h> //for fmod

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found
#define MAXVAL 100 //maximum size of value stack
#define BUFSIZE 100 //size of buffer for getch and ungetch

int sp = 0; //next free position in value stack
double val[MAXVAL]; //value stack
char buf[BUFSIZE]; //buffer for getch and ungetch
int bufp = 0; //next free position in buffer

int getop(char []);
int getch();
void ungetch(int);
void push(double);
double pop();

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s)); //push number into stack
                break;
            case '+':
                push(pop() + pop()); //add the last two numbers in the stack and push the result
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2); //ensures the second number that appears is subtracted from the first
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: division by zero");
                }
                break;
            case '%':
                op2 = pop();
                if(op2 != 0) {
                    push(fmod(pop(), op2)); //modulus function for doubles
                } else {
                    printf("error: division by zero");
                }
            case 'v': //view the top element of the stack
                printf("\t%f\n", val[sp - 1]);
                break;
            case 'd': //duplicate the top element of the stack
                double elem = val[sp - 1];
                val[sp++] = elem;
                break;
            case 's': //swap the top two elements of the stack
                double val1 = pop();
                double val2 = pop();
                push(val1);
                push(val2);
                break;
            case 'c': //clear the stack
                sp = 0;
                break;
            default:
                printf("error: unknown command %s\n", s);
        }
    }
}

void push(double f) {
    if(sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full");
    }
}

double pop() {
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty");
        return 0.0;
    }
}

//get next operator or operand
int getop(char s[]) {
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-') {
        return c; //c is not a number
    }
    i = 0;
    if(isdigit(c)) { //get integer part of operand
        while(isdigit(s[++i] = c = getch()));
    }
    if(c == '.') { //get decimal part
        while(isdigit(s[++i] = c = getch()));
    }
    if(c == '-') {
        if(isdigit(c = getch()) || c == '.') {
            s[++i] = c; //negative number
        } else {
            if(c != EOF) {
                ungetch(c);
            }
            return '-'; //minus
        }
    }
    s[i] = '\0';
    if(c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

//get a character from buffer or input
int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//push character back to buffer
void ungetch(int c) {
    if(bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}