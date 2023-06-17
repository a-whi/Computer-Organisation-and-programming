#include <stdio.h>
#include <math.h>

float approx(int n, float x){

    float sum = 0;
    for(int i = 0; i<n; i++){
        int current = 2*i+1;
        sum = sum + pow(-1, i) * pow(x, current) / tgamma(current + 1);
    }

    return sum;
}

// int main(int argc, char *argv[]){
int main(){
    // int n = atoi(argv[1]); Used for negative numbers
    // double x = atof(argv[2]); Used for converting to doubles
    float x = 3.14;
    int n = 10;

    float value = approx(n, x);
    printf("%f", value);

    return 0; 
}