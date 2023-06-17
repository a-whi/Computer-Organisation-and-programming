#include <stdio.h>

int main(int argc, char *argv[]){
    
    int value;
    
    // Opens the file
    FILE *readfile = fopen(argv[1], "r");

    if (readfile == NULL){
        printf("File cannot be opened\n");
        return 1;
    } 

    // Get size of array
    fscanf(readfile, "%d", &value);

    int arr[value];

    //Add all values to the array
    for (int i = 0; i < value; i++){
        fscanf(readfile, "%d", &arr[i]);
    }

    for (int i = 0; i < value; i++){
        for (int j = 0; j < value - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < value; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(readfile);
    return 0; 
}