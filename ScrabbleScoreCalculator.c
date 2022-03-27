/*  Savvas Misailidis
 *  --------------------------------------
 *  Input: Word
 *  --------------------------------------
 *  This code, its a ScrabbleScore calculator.
 *  --------------------------------------
 *  Output: points
*/

#include <stdio.h>
#include "string.h"

#define max 21

/* Functions */
int scrabbleScore(int maxx, char charr[]);
/*  */

int main() {

    /* Declarations and Variable Initializations */
    char charr[max];
    int points ;
    /*  */

    /* Inputs */
    printf("Give a word with letters between 1-20: ");
    gets(charr);
    /*  */

    /* Function Call */
    points = scrabbleScore(max, charr);
    /*  */

    /* Outputs */
    printf("---------------------------------------------\n");
    printf("The points you got from the word %s are: %d", charr, points);
    /*  */

    return 0;
} // END main()

/* Functions */
int scrabbleScore(int maxx,  char charr[]){

    int i, p=0;

    for(i=0;charr[i] != '\0'; i++){
        if (charr[i] == 'A' || charr[i] == 'E' || charr[i] == 'I' || charr[i] == 'L' || charr[i] == 'N' || charr[i] == 'O' || charr[i] == 'R' || charr[i] == 'S' || charr[i] == 'T' || charr[i] == 'U')
            p++;
        if (charr[i] == 'D' || charr[i] == 'G')
            p = p + 2;
        if (charr[i] == 'B' || charr[i] == 'C' || charr[i] == 'M' || charr[i] == 'P')
            p = p + 3;
        if (charr[i] == 'F' || charr[i] == 'H' || charr[i] == 'V' || charr[i] == 'W' || charr[i] == 'Y')
            p = p + 4;
        if (charr[i] == 'K')
            p = p + 5;
        if (charr[i] == 'J' || charr[i] == 'X')
            p = p + 8;
        if (charr[i] == 'Q' || charr[i] == 'Z')
            p = p + 10;
    }

    return p;
}
/*  */
