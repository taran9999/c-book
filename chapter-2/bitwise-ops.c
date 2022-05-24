#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {

}

//Get n bits starting from position p from unsigned x
unsigned getbits(unsigned x, int p, int n) {
    /* 
    x >> (p + 1 - n) moves desired sequence of bits to the right edge
    ~(~0 << n) creates a mask with n ones at right edge, 0 everywhere else
    */
    return x >> (p + 1 - n) & ~(~0 << n);
}

//Set n bits from position p of x to the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & (~(~(~0 << n)) << (p + 1 - n))) | ((y & (~(~0 << n))) << (p + 1 - n));
}