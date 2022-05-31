#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);

int main() {
    printf("7 (3 bits): bitcount: %d, bitcount2: %d\n8 (1 bit): bitcount: %d, bitcount2: %d\n", bitcount(7), bitcount2(7), bitcount(8), bitcount2(8));
}

//count 1 bits in x
int bitcount(unsigned x) {
    /*
    Right shift x until x = 0
    x & 01 masks x with the integer 1, which masks off all bits except for the rightmost one
    if x & 01 is not 0 (meaning true), there must be a 1 in the rightmost position, so count is incremented
    */
    int b;
    for(b = 0; x != 0; x >>= 1) {
        if(x & 01) {
            b++;
        }
    }
    return b;
}

//Faster version of bitcount, using the fact that x &= (x - 1) deletes the rightmost bit of x
int bitcount2(unsigned x) {
    /*
    x &= (x - 1) deletes the rightmost bit of x, because x - 1 always has the rightmost bit of x set to 0
    Depending on the number, it will also shift the place value down. This is when the rightmost 1 is detected. (eg. 1001 -> 1000 -> 0111)
    */
   int b;
   for(b = 0; x != 0; x &= (x - 1)) {
       b++;
   }
   return b;
}