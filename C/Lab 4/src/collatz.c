#include <stdio.h>
#include <stdlib.h>

void res_function(int number){
    if (number == 1){
        printf("\n ");
    }else if (number % 2 == 0){
        number = number / 2;
        printf("%d ", number);
        res_function(number);
    }else{
        number = number * 3;
        number++;
        printf("%d ", number);
        res_function(number);
    }
}
int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
    printf("%d ", number);
    
    res_function(number);

    return 0;
}