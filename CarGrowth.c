/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: cars, annual growth rate, limit
 *  --------------------------------------
 *  This code, calculates in how many years car growth rate will reach the limit.
 *  Also, calculates how many cars will be manufactured.
 *  --------------------------------------
 *  Output: years, cars
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main () {

    /* Declarations and Variable Initializations */
    long cars;
    int years = 0;
    double rate;
    long initialNumberOfCars;
    long limit;
    /*  */

    /* Inputs */
    printf("Give the amount of cars: ");
    initialNumberOfCars = GetLong();

    printf("Give annual growth rate: ");
    rate = GetReal();

    printf("Give the limit: ");
    limit = GetLong();
    /*  */

    cars = initialNumberOfCars;

    /* Data processing */
    while(cars <= limit ) {
        cars =ceil( cars * (1 + rate));
        years++;
    }
    /*  */

    /* Outputs */
    printf("The limit will be reached in %d years\n", years);
    printf("The quantity of cars built is %ld\n",cars);
    /*  */

    return 0;
} // END main()
