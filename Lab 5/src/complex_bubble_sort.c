#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *readfile = fopen(argv[1], "r");

    if (readfile == NULL){
        printf("File cannot be opened\n");
        return 1;
    }

    int row;
    int col;

    fscanf(readfile, "%d %d", &row, &col);

    int **arr = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++){
        arr[i] = malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            fscanf(readfile, "%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < row; i++){
        for (int k = 0; k < col-1; k++){ // Added loop for bubble sort passes
            for (int j = 0; j < col-1-k; j++){
                if (arr[i][j] > arr[i][j+1]){
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][j+1];
                    arr[i][j+1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);

    fclose(readfile);

    return 0;
}
