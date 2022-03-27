/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: Temper
 *  --------------------------------------
 *  This code, calculates the average temperature of all cities, the average temperature on each city
 *  the deviation on each city, between the average temperature of all cities and temper of each city,
 *  and the max deviation.
 *  --------------------------------------
 *  Output: Average temper of all cities, Max deviation
*/

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

/* Functions */
void readData(int rows, int cols, double temper[rows][cols]);
double calculateAverage(int rows, int cols, double temper[rows][cols]);
void calculateAvgCity(int rows, int cols, double temper[rows][cols], double average[rows]);
void calculateMaxDeviation(int rows, int cols, double temper[rows][cols], double mdeviation[], double natavg);
void printResults(double natavg, int rows, double average[], double mdeviation[]);
/*  */

int main() {

    /* Declarations and Variable Initializations */
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;
    /*  */

    /*Read all Temperatures*/
    readData(CTS, S, temper);
    /*  */

    /*Calculating The Average of all Cities&Temps*/
    natavg = calculateAverage(CTS, S, temper);
    /*  */

    /*Calculating Average temp on each City*/
    calculateAvgCity(CTS, S, temper, average);
    /*  */

    /*Calculating Standard Deviation*/
    calculateMaxDeviation(CTS, S, temper, mdeviation, natavg);
    /*  */

    /*Printing results*/
    printResults(natavg, CTS, average, mdeviation);
    /*  */
} // END main()

/* Functions */
void readData(int rows, int cols, double temper[rows][cols]) {

    int i,j;

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            printf("Temp of City %d During %d 8-hour period: ",i,j);
            temper[i][j] = GetReal();
        }
    }
}

double calculateAverage(int rows, int cols, double temper[rows][cols]) {

    int i,j;
    double natavg=0;

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j+=1){
            natavg += temper[i][j];
        }
    }
    natavg = natavg/(rows * cols);
    return natavg;
}

void calculateAvgCity(int rows, int cols, double temper[rows][cols], double average[rows]) {

    int i,j;

    for (i=0; i<rows; i++){
        average[i] = 0;
        for (j=0; j<cols; j++){
            average[i] += temper[i][j];
        }
        average[i] = average[i]/cols;
    }
}

void calculateMaxDeviation(int rows, int cols, double temper[rows][cols], double mdeviation[], double natavg) {

    int i, j;
    double devnat[rows][cols];

    /*Calculating Standard Deviation*/
    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            devnat[i][j] = fabs(natavg-temper[i][j]);
        }
    }
    /*  */

	/*Calculating max Deviation*/
    for (i=0; i<rows; i++){
        mdeviation[i] = devnat[i][0];
        for(j=1; j<cols; j++){
            if (mdeviation[i]<devnat[i][j]){
                mdeviation[i] = devnat[i][j];
            }
        }
    }
    /*  */
}

void printResults(double natavg, int rows, double average[], double mdeviation[]) {

    int i;

    printf("%3.1f\n", natavg);
    for (i=0; i<rows; i+=1){
        printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
    }
}
/*  */
