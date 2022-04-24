#include <stdio.h>

//Program for counting number of characters in input
main() {
    /* 1st version
    long nc; //long is at least 32 bits, as opposed to ints which are usually 16

    nc = 0;
    while(getchar() != EOF) {
        ++nc;
    }
    printf("%1d\n", nc);
    */

   //2nd version
   double nc; //double precision float, able to handle even larger numbers
   for(nc = 0; getchar() != EOF; ++nc) {
       ; //called a null statement, lets you do nothing while fulfilling grammatical rules
   }
   printf("%.0f\n", nc);

}