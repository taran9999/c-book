#include <stdio.h>

//printing fahrenheit-celsius conversion table for 0 to 300 degrees fahrenheit
main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; //lower limit of table
    upper = 300; //upper limit
    step = 20;

    //header for table
    printf("%3s %6s\n", "F", "C");

    fahr = lower;
    while(fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9; //integer division truncates, simply multiplying by 5/9 would cause everything to be 0
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/*
printf for printing formatted strings
%d = integer argument
%f = float argument
%6d = integer argument to be printed at least 6 characters wide
%.2f = float argument to be printed with two digits after decimal point
%6.2f = 6 characters wide and 2 digits after decimal point
%o = octal
%x = hexadecimal
%c = character
%s = character string
%% = %
*/