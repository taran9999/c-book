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
    /* Strategy:
    Get rightmost n bits of y by masking with ~(~0 << n)
    Turn off n bits at position p in x by masking with ~((~(~0 << n)) << (p + 1 - n)) (mask looks like 11100011, n zeroes at position p)
    Left shift y by (p + 1 - n) to line up with off bits of x
    x | y results in structure similar to xxxyyyxx
    */

    return (x & (~((~(~0 << n)) << (p + 1 - n)))) | ((y & (~(~0 << n))) << (p + 1 - n));
}