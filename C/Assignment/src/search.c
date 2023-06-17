// Task 3 Efficient Search
// Created By : Alexander Whitfield 
// ID : 32541767

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stats.h"
#include "provided_functions/2071_hash.h"
#include "provided_functions/2071_files.h"
#include "provided_functions/2071_image.h"


// I have created two structs
typedef struct knownData{
	char filename[101]; // Setting the number of characters as 50 since the filename shouldn't be over 50
	float mean; // mean and variance were set in the last task as float values so I have kept it that way
	float variance; // Using float instead of double to save memory, although it's less accurate
	char hash[65]; // SHA_256 have a length of 64 characters, I've added 1 more as I add a NULL charater at the end of the string
}knownData;

typedef struct unknownData{
	char filename[101]; // Setting the number of characters as 50 since the filename shouldn't be over 50
	float mean; // mean and variance were set in the last task as float values so I have kept it that way
	float variance; // Using float instead of double to save memory, although it's less accurate
	char hash[65]; // SHA_256 have a length of 64 characters, I've added 1 more as I add a NULL charater at the end of the string
}unknownData;


/**
 * Quicksort function, used to sort the known data by its mean.
 * These are a group of functions that make up quicksort. 
 * The function picks an element as the pivot and then partitions the array around it.
 * 
 * I used GeeksforGeeks' pseudo code to help me write this code: https://www.geeksforgeeks.org/quick-sort/
 *
 * @param knownData arr[], int low, int high
 * 
 * knownData arr[] = an array of the knownData structs
 * low = the starting index,
 * high = the end index
 *  
 * @return - None (The array will have been sorted)
 */

// This function just swaps the elements in the array
void swap(knownData *a, knownData *b){
	knownData temp = *a;	// Create a temp to store the data
	*a = *b;	// Then to swap the data I make a = b
	*b = temp;	// Then set b to equal temp
}
 
// Partition the array using the last element as the pivot
int partition(knownData arr[], int low, int high)
{
    // Cereating the pivot
    float pivot = arr[high].mean;
     
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);
 
	// Iterates through the list 
    for (int j = low; j <= high - 1; j++) {
         
        // If current element is smaller than the pivot
        if (arr[j].mean < pivot) {
             
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
	// All elements that are higher than the pivot
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive function to sort the array
void quickSort(knownData arr[], int low, int high)
{

    if (low < high) {	// If the starting index is less than the higher index
         
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);
         
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);   // Sort the elements smaller than the index
        quickSort(arr, pi + 1, high);	// Sort the elements larger than the index
    }
}


/**
 * binary_search function is used to find the index of the target value and return it.
 * I've used it as its time complexity is O(log(N)) making it great for finding a target value.
 * 
 * The function contains an if statement in the while loop so it can work for both hash and mean values.
 * Hash and mean are different data types, hash = char, mean = float.
 * The mean should never == -1 so when it has to find the mean target it will always work
 * 
 * I used GeeksforGeeks' pseudo code to help me write this code: https://www.geeksforgeeks.org/binary-search/
 * I then modified it to work for the hash values as well.
 *
 * @param int target, int data_size
 * target - The image that we are looking for
 * hash_target - the taget for the hash value
 * mean_target - the taget for the mean value
 * data_size - The length of the array we are searching through
 *  
 * @return either 'mid' or -1
 * mid is the index of the target
 * -1 is returned if it can't find the target values
 */
int binary_search(knownData arr[], char* hash_target, float mean_target, int data_size){

	int low = 0;
	int high = data_size - 1;
	int index;

	while (low <= high){
		// Find midpoint
		int mid = low + (high - low) / 2;

		if (mean_target == -1){
			// For finding hash target
			// Check if target is at the midpoint:
			if (strcmp(hash_target, arr[mid].hash) == 0){
				// if so then it returns the mid value (the index)
				return mid;
			// If the value at mid is higher the low index is changed
			}else if (strcmp(hash_target, arr[mid].hash) < 0){
				low = mid + 1;
			}else{
				// If the value at mid is lower the high index is changed
				high = mid - 1;
			}
		}
		else{
			// For finding mean target
			// Check if target is at the midpoint:
			if (mean_target == arr[mid].mean){
				// if so then it returns the mid value (the index)
				return mid;
			// If the value at mid is higher the low index is changed
			}else if (arr[mid].mean < mean_target){
				low = mid + 1;
			}else{
				// If the value at mid is lower the high index is changed
				high = mid - 1;
			}
		}

	}
	// If target isn't found then return -1
	return -1;
}


/**
 * The addImageData_toStruct function basically copied from the previous task. I did try to just call the previous task originally
 * in the main file, although I ran into problems and thought it just easier to the copy the code over. 
 * 
 * This is benificial though as I added a quicksort function to task 2 to sort the file by hash values as time isn't marked in the 
 * previous task. This means that in this function I only have to quicksort once keeping the run time short.
 *
 * @param char *directory, int *file_count
 *  
 * @return file_data
 * file_data is an array of structs 
 */
// This function returns the allocated memory for the file_data array, which is a pointer to an array of data_image struct
unknownData *addImageData_toStruct(char *directory, int *file_count){
	// This will find all the files that are in the data base
	// Stores a list of all the filenames in the given directory into an array
	char **filenames = query_filenames(directory, file_count);	

	// Allocate the memory to for all the files
	// file_data is an array of the data_image struct containing image information
	unknownData *file_data = malloc((*file_count) * sizeof(unknownData));

	//Adding the file information to the struct
	for (int i = 0; i < *file_count; i++){

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
	return file_data;
}


/**
 * main function is used to create the two image databases, it does this by taking the images in the directories provided and adding it
 * to a specific struct, which is then used to print the values.
 *
 * @param int argc, char *argv[]
 * These are arguements given to the program,
 * The first is the the directory of images to search 
 * The second is the location of the database file created by the program in the previous task
 *  
 * @return - 0
 * The function prints out the corresponding filenames, but returns nothing
 */
int main(int argc, char *argv[]){
	
	/* 
	  For the unknown images, the first argument.
	  This will find all the files that are in the unknown data base
	  by calling a function that I copyied from task 2 to put the image data into the struct,
	  I ran into problems when I called the function from the previous task 2 so I did it this way
	*/

	int file_count; // File counter
	unknownData *file_data = addImageData_toStruct(argv[1], &file_count);
	// We will find all the image data and add it to the unknownData struct, from there we can compare them to the knownData struct

	// For the second command arguemnt we will copy the data into the knowndata struct as everything has already been calculated from the second task
    // Opens the file
    FILE * readfile = fopen(argv[2], "r");
	char line[110]; // length of the lines in database.tsv

	int lineCount = 1000; // The number of structs that are made, this is a fixed number as specified in the document assumptions

	// Allocates the space for the array
	knownData *known_file_data = malloc(lineCount * sizeof(knownData));

	// This will skip the header line of the file
	fgets(line, sizeof(line), readfile);

	int i = 0;
	while (fgets(line, sizeof(line), readfile)){
		// Add values into the knownData struct
		char filename[50];
		float mean;
		float variance; 
		char hash[65];

		sscanf(line, "%s\t%f\t%f\t%s", filename, &mean, &variance, hash);

		// Copying the image filename and hash as they are strings
		strncpy(known_file_data[i].filename, filename, sizeof(known_file_data[i].filename)-1);
        known_file_data[i].filename[sizeof(known_file_data[i].filename)-1] = '\0'; // Signals the end of the string 
		known_file_data[i].mean = mean;
		known_file_data[i].variance = variance;
		strncpy(known_file_data[i].hash, hash, sizeof(known_file_data[i].hash)-1);
        known_file_data[i].hash[sizeof(known_file_data[i].hash)-1] = '\0'; // Signals the end of the string 
		i++;
	}

	// Printing out the file matches

	printf("unknown\tknown\n");	// Header

	// I set target_mean as -1 so when binary search is called first it runs the hash version
	int target_mean = -1;

	// For loop, call binary search, then print the files it finds
	for(int i = 0; i < file_count; i++){
		// Set the target hash value
		char target_hash[65];
		strcpy(target_hash, file_data[i].hash);

		// Call binary search
		int index = binary_search(known_file_data, target_hash, target_mean, lineCount);

		// Binary search return -1 for transformed images as the hash isn't always identical
		if (index != -1){
			printf("%s\t%s\n", file_data[i].filename, known_file_data[index].filename);

		// This is for the tranformed images as their hashes might be different so we will compare their mean 
 		}else{
			// I set the hash values to -1 as the hash values aren't needed
			strcpy(file_data[i].hash, "-1");
		}
	}

	// Now I call quicksort to resort the array by their mean values
	quickSort(known_file_data, 0, lineCount -1);

	char target_hash[65];	// Create a target hash which is blank to pass it into the binary search function
	// This will loop though the unknown data, but looking for hashes of -1 
	for(int i = 0; i < file_count; i++){
		if (strcmp(file_data[i].hash, "-1") == 0){
			float target_mean = file_data[i].mean;	// Set the target
			int index = binary_search(known_file_data, target_hash, target_mean, lineCount);
			printf("%s\t%s\n", file_data[i].filename, known_file_data[index].filename);
		}
	}

	// Free all memory allocated
	free(file_data); // Freeing the memory for the array
	free(known_file_data);

	fclose(readfile);

	return 0;
}