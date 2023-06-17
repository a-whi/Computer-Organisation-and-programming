// Program to run mean function on given inputs for testing purposes
// Copyright © 2023 Copyright, Monash University
#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main(int argc, char *argv[])
{
    // Exit if no input values are given
    if (argc < 2)
    {
        fprintf(stderr, "Error. Please enter at least one argument\n");
        return -1;
    }

    // Create input array from values passed in argv
    int array_length = argc - 1;
    int *input_array = malloc(array_length * sizeof(int));
    for (int i = 0; i < array_length; i++)
    {
        input_array[i] = atoi(argv[i+1]);
    }

    // Print input array
    // printf("Input array: ");
    // for (int i = 0; i < array_length; i++)
    // {
    //    printf("%d, ", input_array[i]);
    // }
    // printf("\n");

    // Compute and report mean
    float mean = compute_mean(input_array, array_length);
    free(input_array);
    // printf("Mean: ");
    printf("%f\n", mean);

    return 0;
}