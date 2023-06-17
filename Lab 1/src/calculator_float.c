#include <stdio.h>
#include <math.h>

int main (void) {

    double number_1;
    double number_2;
    char symbol;

    double sum;

    scanf("%lf %c %lf", &number_1, &symbol, &number_2);

    if (symbol == '+'){
        sum = number_1 + number_2;
        printf("%lf\n",sum);
    }else if(symbol == '*'){
        sum = number_1 * number_2;
        printf("%lf\n",sum);
    }else if(symbol == '-'){
        sum = number_1 - number_2;
        printf("%lf\n",sum);
    }else if(symbol == '/'){
        sum = number_1 / number_2;
        printf("%lf\n",sum);
    }else if(symbol == '%'){
        sum = fmod(number_1,number_2);
        printf("%lf\n",sum);
    }

    return 0; 
}
/*
In the original file 'calculator.c' all values are integers meaning they have no
decimal values. When doing division the answer is always an integer rounded down
(so there is a remained). Although in 'calculato_float.c' all inputs are doubles
meaing they can have floating values, when divising we always get the excact value.
The modulus symbol '%' gives the remained to any division equation. In both files 
the modulus gives the same value although in the float file we get decimal zeros 
cause the values are doubles. 
*/

