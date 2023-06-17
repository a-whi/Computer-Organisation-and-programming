#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Task 1: Write two C functions `mean` and `median` that each takes a string as input, and perform the following operations:
(a) Calculate the mean character of the string, counting only upper case alphabetical characters
(b) Calculate the median character of the array
(c) Print the mean and median in the following format:
Mean: <mean character>
Median: <median character>
(eg: The word "Mean", a colon, a space, and then mean character, followed by a newline)
*/

// Task 1 mean function
void mean(char *string){

    // Here I add the ASCII values of each letter into the sum
    // Then divide by the string length
    // Then print the corresponding ASCII letter
    int sum = 0;
    int stringLen = strlen(string);

    for (int i = 0; i < stringLen; i++){
        sum += string[i];
    }

    char mean = sum/stringLen;

    printf("Mean: %c\n", mean);
}

// Task 1 Median function
void median(char *string){
    // Here I just find the length of the string
    // I use if statements incase the string length is even or odd
    char median;
    int stringLen = strlen(string);
    int medianValue = stringLen%2;

    if (medianValue == 0){
        median = string[stringLen/2];
    }else{
        median = string[stringLen/2];
    }

    printf("Median: %c\n", median);
}

/*Task 2: In the main function, write code that does the following:
read in a string (this has been done for you in the skeleton)
call your `median` function and your `mean` function to get the output statistic of the array that was read in
print this result to the terminal in the format specified above(you should not print anything else to the terminal)
free any memory that was allocated by any of your functions*/

int main(){

    // Set the string input as 100 characters
    char string[100];
    // As the input is only upper case characters there should be no white spaces, so scanf should be fine
    scanf("%99s", string);

    // Call the functions
    mean(string);
    median(string);

    return 0;
}