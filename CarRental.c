/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: number of cars, brand, CC, name of client, days of reservation, daily charge
 *  --------------------------------------
 *  This code, calculates in how many years car growth rate will reach the limit.
 *  Also, calculates how many cars will be manufactured.
 *  --------------------------------------
 *  Output: Best car for rental, total charge for each car
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>

#define RENTS 20

/* Structs */
typedef struct {

    int number;
    int days;
    int cc;
    char type[20];
    char name[20];
    float daily_rate;
    float total_charge;
} car_rentalT;

typedef struct {

  char type[20];
  int cc;
  float amount;
}best_carT;
/*  */

/* Functions */
int getData(car_rentalT rentals[]);
float calcTotals(int numRentals, car_rentalT rentals[]);
best_carT findBest(int numRentals, car_rentalT rentals[]);
void printData(int numRentals, car_rentalT rentals[], float total, best_carT best);
/*  */

int main(){

    /* Declarations and Variable Initializations */
    car_rentalT rentals[RENTS];
    best_carT bestCar;
    int numRentals;
    float total;
    /*  */

    /* Function Call */
    numRentals = getData(rentals);

    total = calcTotals(numRentals, rentals);

    bestCar = findBest(numRentals, rentals);

    printData(numRentals, rentals, total, bestCar);
    /*  */

    return 0;
} // END main()

/* Functions */
int getData(car_rentalT rentals[]){

    int i, numRentals;

    printf("Give number of cars: ");
    numRentals = GetInteger();

    for (i=0; i<numRentals; i++){

        /* Inputs */
        printf("Client number %d\n", i+1);
        rentals[i].number = i;

        printf("Give brand: ");
        gets(rentals[i].type);

        printf("Give CC: ");
        rentals[i].cc = GetInteger();

        printf("Name of Client? ");
        gets(rentals[i].name);

        printf("Give days of reservation: ");
        rentals[i].days = GetInteger();

        printf("Give daily charge: ");
        rentals[i].daily_rate = GetReal();
        /*  */

    }
    return numRentals;
}

float calcTotals(int numRentals, car_rentalT rentals[]){

    int i;
    float total = 0;

    for(i=0; i<numRentals; i++){
        rentals[i].total_charge = rentals[i].days * rentals[i].daily_rate;
        total +=  rentals[i].total_charge;
    }
    return total;
}

best_carT findBest(int numRentals, car_rentalT rentals[]){
    int i;
    best_carT best;

    strcpy(best.type, rentals[0].type);
    best.cc = rentals[0].cc;
    best.amount = rentals[0].total_charge;


    for(i=1;i<numRentals;i++){
        if(best.amount<rentals[i].total_charge){
            strcpy(best.type, rentals[i].type);
            best.cc = rentals[i].cc;
            best.amount = rentals[i].total_charge;
        }
    }
    return best;
}

void printData(int numRentals, car_rentalT rentals[], float total, best_carT best){

    int i;

    /* Outputs */
    printf("\n\n");
    printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n","Number", "Name", "Type", "CC", "Days", "Price", "Total");

    for(i=0;i<73;i++){
        printf("-");
    }
    printf("\n");

    for(i=0; i<numRentals;i++){

        printf("%-7d %-20s %-10s %-5d %-5d %-6.2f %-8.2f\n",
        rentals[i].number+1,
        rentals[i].name,
        rentals[i].type,
        rentals[i].cc,
        rentals[i].days,
        rentals[i].daily_rate,
        rentals[i].total_charge);
    }

    for(i=0;i<73;i++){
        printf("-");
    }
    printf("\n");

    printf("%58s %-8.2f\n", "Total", total);
    printf("Best car: %s %d rented for %.2f Euro.\n", best.type, best.cc, best.amount);
    /*  */
}
/*  */
