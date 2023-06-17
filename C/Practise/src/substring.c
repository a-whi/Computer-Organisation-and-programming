#include <stdio.h>
#include <string.h>

int main()
{
    char string_1[40] = "abcd efghl ijkl mnop";

    //Your code goes here
    int letterCount= 0;
    int longest = 0;
    char substring[100]= "";
    char longestsub[100] = "";

    for(int i = 0; i < strlen(string_1); i++){
        if(string_1[i] == ' ' || string_1[i] == '\0'){
            if(letterCount > longest){
                longest = letterCount;
                strcpy(longestsub, substring);
            }
            letterCount = 0;
            strcpy(substring, "");

        }else{
            strncat(substring, &string_1[i], 1); // Used to add 1 character to a string
            //strcat(substring, &string_1[i]); // Used to join 2 strings
            letterCount++;
        }
    }

    printf("%s\n", longestsub);

    return 0;
}