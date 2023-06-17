#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// get words from file and store in array

int main(){
    char arr[80][100]; // Each string can hold up to 99 characters + '\0'
    FILE * readfile = fopen("text.txt", "r");

    if (readfile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for(int i = 0; i < 80; i++){
        fgets(arr[i], 100, readfile);
    }

    if (fclose(readfile) != 0) {
        printf("Error closing file\n");
        return 1;
    }
    return 0;
}
// For numbers:

// int main(){
//     int arr[80];
//     FILE * readfile = fopen("text.txt", "r");

//     if (readfile == NULL) {
//         printf("Error opening file\n");
//         return 1;
//     }

//     for(int i = 0; i < 80; i++){
//         fscanf(readfile, "%d", &arr[i]);
//     }

//     if (fclose(readfile) != 0) {
//         printf("Error closing file\n");
//         return 1;
//     }
//     return 0;
// }

