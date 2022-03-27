/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: age, weight, height, sex
 *  --------------------------------------
 *  This code, calculates Basal Metabolic Rate for a girl or a guy
 *  --------------------------------------
 *  Output: Basal Metabolic Rate (BMR)
*/

 #include <stdio.h>
 #include "genlib.h"
 #include "simpio.h"
 #include <ctype.h>

int main() {

    /* Declarations and Variable Initializations */
    int age, weight, height;
    char sex; //Male, Female
    double BMR ; //Basal Metabolic Rate
    /*  */

    /* Inputs */
    printf("Give your kg: ");
    weight = GetInteger();

    printf("Give your height(cm): ");
    height = GetInteger();

    printf("Give your age: ");
    age = GetInteger();
    /*  */

    /* Data processing */
    do {
        printf("Give your sex (m or M for male) | (f or F for female): ");
        sex = getchar();
    }while(toupper(sex) != 'M' && toupper(sex)!= 'F');

    if((sex == 'm' || sex == 'M')){
        BMR =  88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    }
    else{
        BMR =  447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
    /*  */

    /* Output */
    printf("To BMR einai %g\n", BMR);
    /*  */

    return 0;
 } // END main()
