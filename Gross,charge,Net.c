/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: Hours of work, hourly wages, rate of charges
 *  --------------------------------------
 *  This code, calculates the gross earnings,
 *  the earnings that got lost due to charges and
 *  the net salaries of a worker
 *  --------------------------------------
 *  Output: Gross earnings, charge, Net earnings
*/

  #include <stdio.h>
  #include "genlib.h"
  #include "simpio.h"

int main() {

    /* Declarations and Variable Initializations */
    int workingHours;
    long hourlyFee;
    double rate, netProfits, charges, grossEarnings;
    /*  */

    /* Inputs */
    printf("Give working hours: ");
    workingHours = GetInteger();

    printf("Give hourly wages: ");
    hourlyFee = GetLong();

    printf("Give a percentage of charges: ");
    rate = GetReal();
    /*  */

    /* Data processing */
    netProfits = workingHours * hourlyFee;
    charges = netProfits * rate;
    grossEarnings = netProfits + charges;
    /*  */

    /* Outputs */
    printf("Gross salaries are %g\n", grossEarnings);
    printf("The charges are %g\n", charges);
    printf("The net salaries are %g\n", netProfits);
    /*  */

    return 0;
} // END main()
