#include <stdio.h>
int main (void) {

    int number_1;
    int number_2;
    char symbol;

    int sum;

    scanf("%d %c %d", &number_1, &symbol, &number_2);

    if (symbol == '+'){
        sum = number_1 + number_2;
        printf("%d\n",sum);
    }else if(symbol == '*'){
        sum = number_1 * number_2;
        printf("%d\n",sum);
    }else if(symbol == '-'){
        sum = number_1 - number_2;
        printf("%d\n",sum);
    }else if(symbol == '/'){
        sum = number_1 / number_2;
        printf("%d\n",sum);
    }else if(symbol == '%'){
        sum = number_1 % number_2;
        printf("%d\n",sum);
    }

    return 0; 
}