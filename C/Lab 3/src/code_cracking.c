#include <stdio.h> //Normal library
#include <stdlib.h>


int main(int argc, char *argv[]){

    //Opens the file
    FILE * readfile = fopen(argv[1], "r");

    //If file not found 'error'
    if (readfile == NULL) {
        printf("file can't be opened \n");
        return 1;
    }

    int row;
    int col;

    fscanf(readfile, "%d %d", &row, &col);


    //Allocates memory for the number of columns
    int **array = malloc(col * sizeof(int *));

    //Allocate memory for the rows in each column
    for (int i = 0; i < col; i++){
        array[i] = malloc(row * sizeof(int));
    }
    //Insert the numbers from the file into the array
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            fscanf(readfile, "%d", &array[i][j]);
        }
    }
    //Array structure: array[column][row] as this is how the text file is written

    // Print the first column
    for (int i = 0; i < row; i++){
        printf("%d ", array[0][i]);
    }

    // Print the bottom row
    for (int i = 1; i < col; i++){
        printf("%d ", array[i][row-1]);
    }

    // Print the last column backwards
    for (int i = row - 2; i >= 0; i--){
        printf("%d ", array[col-1][i]);
    }

    // Print the first row backwards
    for (int i = col - 2; i >= 1; i--){
        printf("%d ", array[i][0]);
    }
    printf("\n");

    // Deallocate memory
    // Clears allocated memory for the columns
    for(int i = 0; i < col; i++){
        free(array[i]);
    }
    // Free the allocated memory for the rows
    free(array);
    // Close file
    fclose(readfile);

    return 0;
}