/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: array Data(int)
 *  --------------------------------------
 *  This code, calculates the range of values from an array
 *  by using 2 functions(fullarray & MinMax)
 *  and also with the help of pointers.
 *  --------------------------------------
 *  Output: The Range of values from array
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* Functions */
void fullarray(int size, int *p, int array[size]);
void MinMax(int size, int p, int array[size], int *min, int *max);
/* */

int main() {

    /* Declarations and Variable Initializations */
    int p=0, S=100, array[S];
    int min=100000; //random value
    int max=-1; //random value
    /*  */

    printf("Enter the elements of the array, one per line\n");
    printf("Use -1 to signal the end of the list.\n");

    /* Function Call */
    fullarray(S, &p, array);
    MinMax(S, p, array, &min, &max);

    /* Outputs */
    printf("The range of Values is %d-%d", min, max);
    /*  */

    return 0;
} // END main()

/* Functions */
void fullarray(int size, int *p,int array[size]){

    int i, pp=0;

    for(i=0;i<size;i++){
        printf("? ");
        array[i] = GetInteger();
        pp += 1;

        if (array[i] == -1){
            break;
        }
    }

    *p += pp-1;
}

void MinMax(int size,int p,int array[size],int *min,int *max){

    int i;
    int minn=array[0];
    int maxx=array[0];

    for(i=0;i<p;i++){
        if(minn>array[i]){
            minn = array[i];
        }
        if(maxx<array[i]){
            maxx = array[i];
        }
    }

    *max = maxx;
    *min = minn;
 }
/* End of Functions */
