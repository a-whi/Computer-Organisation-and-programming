#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Geeksfor geeks bubble sort that i have modified
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void customSort(int *array_1, int size){
    int i, j;
    bool swapped;
    for (i = 1; i < (size%2) - 1; i = i + 2) {  // SHould only go through the odd values
        swapped = false;
        for (j = 1; j < (size%2)- i - 2; j = j +2) {
            if (array_1[j] > array_1[j + 1]) {
                swap(&array_1[j], &array_1[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
 

int main() {

    // creating an array of size 10:
    int array_1[10] = {6, 3, 56, 753, 232, 5, 46, 5323, 42, 75};

    // printing the original array:
    for (int i = 0; i < 10; i++){
        printf("%d ", array_1[i]);
    }
    // printing a new line:
    printf("\n");

    // calling the function from part 1:
    customSort(array_1, sizeof(array_1));

    // printing the elements at even indices the array:
    for (int i = 0; i < 5; i = i+2){
        printf("%d ", array_1[i]);
    }
    // printing a new line:
    printf("\n");

    // printing the elements at odd indices of the array:
    for (int i = 1; i < 5; i = i+2){
        printf("%d ", array_1[i]);
    }
    // printing a new line:
    printf("\n");

    return 0;

}