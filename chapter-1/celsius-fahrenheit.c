#include <stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%3s %6s\n", "C", "F");

    celsius = lower;
    while(celsius <= upper) {
        fahr = 9 * celsius / 5 + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}