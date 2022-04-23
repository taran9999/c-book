#include <stdio.h>

//defining constants, by convention written in uppercase (values are not limited to just numbers)
#define LOWER 0
#define UPPER 300
#define STEP 20

//the same table, but written more efficiently using a for loop. There is only one variable (fahr).
main() {
    int fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32)); //(5.0/9.0) read as floats
    }
}