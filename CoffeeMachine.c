/*  Savvas Misailidis
*  --------------------------------------
*  Input: coffees, balance
*  --------------------------------------
*  This code, calculates the changes you will take from the vending machine.
*  --------------------------------------
*  Output: change
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {

    /* Declarations and Variable Initializations */
    int coffees, change, balance=0;
    /*  */

    /* Inputs */
    printf("Give your balance? ");
    balance = GetInteger();

    printf("How many coffees do you want? ");
    coffees = GetInteger();
    /*  */

    if (balance - coffees * 70 >= 0 ) {
        /* Data processing */
        change = balance - coffees * 70;
        if (change / 200 >= 0) {
            printf("Change 2E: %d\n", change / 200);
                change = change % 200;
        }
        if (change / 100 >= 0) {
            printf("Change 1E: %d\n", change / 100);
            change = change % 100;
        }
        if (change / 50 >= 0) {
            printf("Change 50L: %d\n", change / 50);
            change = change % 50;
        }
        if (change / 20 >= 0) {
            printf("Change 20L: %d\n", change / 20);
            change = change % 20;
        }
        if (change / 10 >= 0) {
            printf("Change 10L: %d\n", change / 10);
            change = change % 10;
        }
        /*  */
    }
    else {
        /* Inputs */
        printf("You dont have enough money to buy %d coffees", coffees);
        /*  */
    }

    return 0;
} // END main()
