#include <stdio.h>
//13a + 3b + 5c = 2071
int main(){

    int user_input;
    int sum = 2071;
    int total = 0;

    scanf("%d", &user_input);

    for (int a = 0; a < user_input; a++){
        for (int b = 0; b < user_input; b++){
            for (int c = 0; c < user_input; c++){
                total = (13*a) + (3*b) + (5*c);
                if (total == sum){
                    printf("a=%d b=%d c=%d\n",a,b,c);
                    }
            }
        }
    }
    return 0;
}