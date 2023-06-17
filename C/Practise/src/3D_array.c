/*
A 3-dimensional array of size (3,4,5) with zeroes. 
Then I index  all  elements  in  the  array  and  fill  each  element
with  a  random  integer between 33 (inclusive) and 40 (inclusive)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> // For random number generation

int arrayWithMalloc(){

    // seed the random number
    srand(time(NULL));
    // Array dimensions
    int x = 3;
    int y = 4;
    int z = 5;

    // Create an array of length 3
    int ***arr = (int ***)malloc(x * sizeof(int **));

    // In each element in the array have an array of length 4
    for (int i = 0; i < x; i++){

        arr[i] = (int **)malloc(y * sizeof(int *));

        // In each element in the x_axis array have an array of length 5
        for (int j = 0; j < y; j++){
            arr[i][j] = (int *)malloc(z * sizeof(int));
        }
    }

    // Add 0's to each element in the array
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                arr[i][j][k] = 0;
            }
        }
    }

    // Print the 0's
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                printf("%d", arr[i][j][k]);
            }
        }
    }
    printf("\n");

    // Now to make every element in the array a random number between 33 & 40
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                // Genetate a random number between 0 & 7
                int rand_num = rand() % 8;
                // Add it to 33 to get values between 33 & 40
                rand_num += 33;
                arr[i][j][k] = rand_num;
            }
        }
    }

    // Print the random numbers
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                printf("%d", arr[i][j][k]);
            }
        }
    }
    printf("\n");
    
    // Deallocate memory 
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            // Frees 'z' array
            free(arr[i][j]);
        }
        // Frees 'y' array
        free(arr[i]);
    }
    // Frees 'x' array
    free(arr);

    return 0;
}

int simple_3DArray(){
    // seed the random number
    srand(time(NULL));

    // Array dimensions
    int x = 3;
    int y = 4;
    int z = 5;

    // Makes a 3D array of 0's, but can only be done with hard coded values for x, y, z
    int arr[3][4][5] = { 0 };

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                // Genetate a random number between 0 & 7
                int rand_num = rand() % 8;
                // Add it to 33 to get values between 33 & 40
                rand_num += 33;
                arr[i][j][k] = rand_num;
                printf("%d",arr[i][j][k]);
            }
        }
    }
    printf("\n");
    return 0;
}


int main(){

    arrayWithMalloc();
    simple_3DArray();
    return 0;
}