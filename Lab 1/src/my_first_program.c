#include <stdio.h>
#include <math.h>

/*
int addNumbers(int a, int b){
    return a+b;
    // no bracket to close the function
}
//no 'int'
int main() {
    printf("My first program in C\n"); // Mistake 1 print not printf
    // no new line

    // wrong slash
    // defining the key variables
    int v1 = 4; // not semicolon
    float v2 = 5.6;
    int v3 = 10;

    // used # not // for comment
    // check that v1 is bigger than v2
    int checkVal = v1 - v2;
    // print the results // wrong slashes used
    if (checkVal > 0) {
        printf("V1 is greater than V2\n");
        // else statment was wrong
    } else {
        printf("V1 is smaller than V2\n");
    }
    // calling an adition function // wrong slash
    int sum = addNumbers(v1,v3);
    printf("The sum of V1 and v3 is %d\n", sum);

    // no semicolon
    return 0;
}
*/

int main() {
    int year = 2025;
    const int currentYear = 2023;

    int isLeapYear;

    // boolean logic:

    isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year %400 == 0);

    //printing the result:
    if (year < currentYear) {
        if (isLeapYear) {
            printf("The year %d will be a leap year. \n", year);
        }else { 
            printf("The year %d will not be a leap year. \n", year);
        } 
        } else {
            if (isLeapYear) {
                printf("The year %d was a leap year.\n",year);
            }else {
                printf("The year %d was not a leap year. \n",currentYear);
            }
            }
        return 0;

    }