/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: non-negative number
 *  --------------------------------------
 *  This code, calculates the digits, the average of the digits and the max of the digits from a number
 *  --------------------------------------
 *  Output: Digits, average, max
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


/* Functions */
void decompose(long *digits, float *average, long *max, long number);
/*  */

int main() {

    /* Declarations and Variable Initializations */
    long number, digits, max;
    float average;
    /*  */

    /* Inputs */
    printf("Please insert non-negative number:");
    number = GetLong();
    /*  */

    /* Function Call */
    decompose(&digits, &average, &max, number);
    /*  */

    /* Outputs */
    printf("Digits: %ld\n", digits);
    printf("Average: %.3f\n", average);
    printf("Max: %ld", max);
    /*  */

    return 0;
} // END main()

/* Functions */
void decompose(long *digits, float *average, long *max, long number){

    long code;
    int i, x, sum=0, p=0, maxx=-1;

    code = number;

    /* Calculate the digits of the number */
    do{
        x = code % 10;
        p += 1;
        code = code / 10;
    }while(x != 0);
    /*  */

    code = number;

    /* Calculate the max between digits and the sum */
    for(i=p;i>=0;i--){
        x = code % 10;
        sum += x;
        if(maxx < x){
            maxx = x;
        }
        code = code / 10;
    }
    /*  */

    /* Give pointers the values to return */
    if(p != 1 && number != 0){
        *max = maxx;
        *average = (sum/(double)(p-1));
        *digits = p-1;
    }
    else{
        *average = 0;
        *max = 0;
        *digits = 0;
    }
    /*  */
}
/*  */
