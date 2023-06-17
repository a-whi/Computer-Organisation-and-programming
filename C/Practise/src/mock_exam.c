#include <stdio.h>
#include <stdlib.h>

// Finds the next prime number
int prime_number(int num){
    int number = num + 1;

    while(1){
        int prime = 1;
        for(int i = 2; i < number; i++) {
            if((number % i) == 0) {
                prime = 0;
                break;
            }
        }

        if (prime == 1){
            return number;
        }
        number++;
    }
}

// computes hash of each value. 
// (*string_1) will return the ascii value
int string_hash (char* string_1, int starting_value){

    int current_prime = starting_value;
    int accumulator = 0; //A total of all encoded_values

    while(*string_1 != '\0'){
        current_prime = prime_number(current_prime);
        accumulator+= (*string_1) * current_prime;
        string_1++;
    }
    return accumulator;
}

 
int main(){
    char string_1[100];
    int starting_value;
    char filename[100];

    scanf("%s%d", string_1, &starting_value);

    int accumulator = string_hash(string_1, starting_value);

    scanf("%s", filename);
    FILE * new_file = fopen(filename, "a");

    fprintf(new_file, "\n%s %d - %d", string_1, starting_value, accumulator);

    fclose(new_file);

    return 0;
}