/*
Data types:
- char
- int
- float
- double

Random number generator/seeding:
- #include <time.h> // For generating for 'truely' random
-  // Generates random number
    srand(time(0));
-  // This will give a random number between 1-6
    dice = rand() % 6 +1;

String functions:
strcmp() = compares strings
strlen() = length of string
strtok() = splits a string  https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
strcat() = combines words   https://www.geeksforgeeks.org/strcat-in-c/
strncpy = copies a string


ARGV:
int main(int argc, char *argv[]){
    return 0;
}
argv[1], argv[2], ...

Open file:

FILE * readfile = fopen(argv[1], "r");
fclose()

fscanf(readfile, "%d %d", &row, &col); #Scan through each line taking the values

fscanf(...) - take values   fscanf(readfile, "%d", &arr[i]); readfile is filename, %d for integer, &arr to place number in that place
fgetc(...)  -  reads a single character from a file or other input stream. This function is often used in a loop to read characters 
                one at a time until reaching the end of a file or other condition.
fgets(...)  - take string   reads an entire line from a file or other input stream up to a specified length or until it encounters
                a newline character. This function is often used when you want to read a whole line of input at once.
                - fgets(arr[i], 100, readfile);   putting thw string in the array, only up to 100 characters, readfile is the file
                - to get individual characters you can use arr[i]

string arrays:
arr[80][100] - array 80 elements with 100 characters

Write into file:
fprintf(...), fputc(...), fputs(...)

Print to 2 decimal:
- %.2f

How to use malloc:
- Must use stdlib.h
 - void* malloc(size_t size);

int main() {
    int* arr = (int*)malloc(10 * sizeof(int)); // Allocate memory for an array of 10 integers

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return an error code
    }

    // Now you can use the array
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Don't forget to free the memory when you're done
    free(arr);

    return 0;
}
*/