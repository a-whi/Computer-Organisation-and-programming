// Task 2 Database Creation
// Memory used: 526620.0 bytes == 0.526 MB roughly
// Created By : Alexander Whitfield 
// ID : 32541767

#include "stats.h"
#include "provided_functions/2071_hash.h"
#include "provided_functions/2071_files.h"
#include "provided_functions/2071_image.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// I have decided to use a struct to hold the information about the image as I have used this method in a previous lab
typedef struct data_image{
	char filename[101]; // Setting the number of characters as 50 since the filename shouldn't be over 50
	float mean; // mean and variance were set in the last task as float values so I have kept it that way
	float variance; // Using float instead of double to save memory, although it's less accurate
	char hash[65]; // SHA_256 have a length of 64 characters, I've added 1 more as I add a NULL charater at the end of the string
}data_image;


/**
 * This is a quick sort function which is used to sort the data by hash value.
 * I've done this in this file so that in task 3 I dont have to call quicksort to sort it by hash, improving the run time.
 * Quick sort doesn't require much additional memory so won't affect the program specification.
 * 
 * I used GeeksforGeeks' pseudo code to help me write this code: https://www.geeksforgeeks.org/quick-sort/ and modified it
 * to work for the hash values
 *
 * @param data_image arr[], int low, int high
 * arr[] = is the array of data_image
 * low = is the first value
 * high is the last value
 *  
 * @return - None
 */
// Quicksort stuff
void swap(data_image *a, data_image *b){
	data_image temp = *a;
	*a = *b;
	*b = temp;
}

// Partition the array using the last element as the pivot
int partition(data_image arr[], int low, int high) {

	// Set up the pivot
	char pivot[65];
	// Copy the hash so it is the pivot
	strcpy(pivot, arr[high].hash);
    //float pivot = arr[high].mean;

    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(pivot, arr[j].hash) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
// Function to implement Quick Sort
void quickSort(data_image arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// 
/**
 * main function is used to create an image the database, it does this by taking the images in the directory provided and adding it
 * to a struct, which is then used to print the values into a TSV file.
 *
 * @param int argc, char *argv[]
 *  
 * @return - None
 */
int main(int argc, char *argv[]){
	setvbuf(stdout, NULL, _IONBF, 0); // Prevents printf errors

	// This will find all the files that are in the data base
	char *directory = argv[1];
	int file_count; // File counter
	// Stores a list of all the filenames in the given directory into an array
	char **filenames = query_filenames(directory, &file_count);	

	// Allocate the memory to for all the files
	// file_data is an array of the data_image struct containing image information
	data_image *file_data = malloc(file_count * sizeof(data_image));

	//Adding the file information to the struct
	for (int i = 0; i < file_count; i++){

		char *filename = filenames[i];
		// Reads an image from the given file and directory
		Image image = read_image_from_file(directory, filename);

		// Get all information about the image
		int image_width = image.width;
		int image_height = image.height;
		int data_length = image_width * image_height;

		// To get the mean and variance we call the function I previously made
		float mean = compute_mean(image.data, data_length);
		float variance = compute_variance(image.data, data_length); 

		// Creating a unique SHA-256 hash for the image
		char *hash = hash_sha_256_image(&image);

		// Add values into the struct
		// Copying the image filename and hash as they are strings
		strncpy(file_data[i].filename, filename, sizeof(file_data[i].filename)-1);
        file_data[i].filename[sizeof(file_data[i].filename)-1] = '\0'; // Signals the end of the string 
		file_data[i].mean = mean;
		file_data[i].variance = variance;
		strncpy(file_data[i].hash, hash, sizeof(file_data[i].hash)-1);
        file_data[i].hash[sizeof(file_data[i].hash)-1] = '\0'; // Signals the end of the string 


		// Free memory as per the function that were provided
		free(image.data);
		free(hash);
	}

	// Sort the array here by hash so in the next task I dont have to sort it in the next task for the hash values
	quickSort(file_data, 0, file_count -1);

	// The header for the file
	printf("file\tmean\tvariance\thash\t\n");
	// Print the information found in each struct
	for (int i = 0; i < file_count; i++){
		printf("%s\t%f\t%f\t%s\n", file_data[i].filename, file_data[i].mean, file_data[i].variance, file_data[i].hash);
	}

	// Free all memory allocated
	for (int i = 0; i < file_count; i++){
		free(filenames[i]); // Freeing memory for each individual filename in the array
	}
	free(filenames); // Freeing the memory for the array itself
	free(file_data); // Freeing the memory for the array

	return 0;
}