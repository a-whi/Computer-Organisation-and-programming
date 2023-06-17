// Program to apply transformations to a given image
// Copyright © 2023 Copyright, Monash University
#include "2071_image.h"
#include "transformations.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Error. Please enter an image file to test on.\n");
        printf("Usage: ./outputs/transformations_demo ../data/dataset_a/known/known-030.png");
        return -1;
    }
    char *image_filename = argv[1];

    Image image = read_image_from_file(".", image_filename);
    Image orig = copy_image(&image);

    write_image_to_file("original.png", &orig);

    image = copy_image(&orig);
    flip(&image);
    write_image_to_file("flipped.png", &image);
    free(image.data);

    image = copy_image(&orig);
    mirror(&image);
    write_image_to_file("mirrored.png", &image);
    free(image.data);

    image = copy_image(&orig);
    rotate_90_clockwise(&image);
    write_image_to_file("rotated90clockwise.png", &image);
    free(image.data);

    image = copy_image(&orig);
    rotate_180(&image);
    write_image_to_file("rotated180.png", &image);
    free(image.data);

    image = copy_image(&orig);
    rotate_90_anticlockwise(&image);
    write_image_to_file("rotated90anticlockwise.png", &image);
    free(image.data);
    
    free(orig.data);

    printf("Saved images original, flipped, mirrored, rotated90clockwise, rotated180, and rotated90anticlockwise.\n");
}