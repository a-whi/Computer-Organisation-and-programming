// Program to run transformation functions on given inputs for testing purposes
// Copyright © 2023 Copyright, Monash University
#include <stdio.h>
#include <stdlib.h>
#include "2071_image.h"
#include "transformations.h"

int main(int argc, char *argv[])
{
    // Exit if not enough input values are given
    if (argc < 2)
    {
        fprintf(stderr, "Error. Please enter at least one argument\n");
        return -1;
    }

    char operation = argv[1][0];

    // Create image from values passed in argv
    int image_width = atoi(argv[2]); // assume width=height
    int array_length = argc - 3;
    // printf("argc: %d, len: %d, width: %d", argc, array_length, image_width);
    if (array_length != image_width * image_width) {
        fprintf(stderr, "Error. Ensure first argument is image width, image is square, and the correct number of pixel values have been provided.\n");
        return -1;
    }
    int *input_array = malloc(array_length * sizeof(int));
    for (int i = 0; i < array_length; i++)
    {
        input_array[i] = atoi(argv[i+3]);
    }

    Image image;
    image.data = input_array;
    image.width = image_width;
    image.height = image_width;

    // perform transformations
    // report results

    // Perform chosen operation
    switch (operation) {
        case 'f': // flip
        {
            flip(&image);
            break;
        }
        case 'm': // mirror
        {
            mirror(&image);
            break;
        }
        case 'n': // ninety
        {
            rotate_90_clockwise(&image);
            break;
        }
        case 'o': // one-eighty
        {
            rotate_180(&image);
            break;
        }
        case 't': // two-seventy
        {
            rotate_90_anticlockwise(&image);
            break;
        }
    }

    // Display resulting pixels
    for (int i = 0; i < array_length; i++)
    {
        printf("%d", image.data[i]);
        if (i != array_length-1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}