// opening a file taking 100 numbers out
// putting it in a 10x10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    int row = 10;
    int col = 10;
    int total = 0;

    FILE * readfile = fopen("text.txt", "r");

    // Create an array of length 
    int **arr = (int **)malloc(row * sizeof(int *));

    // In each element in the array have an array of length 4
    for (int i = 0; i < row; i++){
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    // Add 0's to each element in the array
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            fscanf(readfile, "%d", &arr[i][j]);
            total+=arr[i][j];
        }
    }

    int mean = total/100;
    printf("%d", mean);

    // Correctly close the file
    if (fclose(readfile) != 0) {
        printf("Error closing file\n");
        return 1;
    }

    // Free allocated memory
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}