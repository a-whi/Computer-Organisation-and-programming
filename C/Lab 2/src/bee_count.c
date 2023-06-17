#include <stdio.h> //Normal library
#include <string.h> //USed for string length stuff
#include <ctype.h> // Used for in punctuation/letter

int main(){

    int bee_count = 0;  //bee counter
    char bee[] = "bee"; //bee is the word we are finding
    char word[100]; //word will be an array of 100 characters so that larger words can be analyised 

    //Opens the file
    FILE * file_bee = fopen("data/bee_movie_script.txt", "r");

    //If file not found 'error'
    if (file_bee == NULL) {
        printf("file can't be opened \n");
        return 1;
    }

    // Reads the words in the file and stores it in 'word' variable
    while(fscanf(file_bee,"%s",word)==1){

        //converts all the letters in the word to lowercase for easy comparison
        for (int i = 0; i < strlen(word); i++){
            word[i] = tolower(word[i]);
        }

        //if word is 3 characters long && the string compare is the same
        if(strlen(word) == 3 && strncmp(word,bee,3)==0){
            bee_count++;
        //if word is bigger than 3 && the last character isn't a letter && the string compare for the first 3 characters is equal to bee
        }else if (strlen(word) > 3 && !isalnum(word[3])&& strncmp(word,bee,3)==0){
            bee_count++;
        }
    }

    printf("There were %d occurances of the word bee in the text\n", bee_count);

    //Closes file
    fclose(file_bee);

    return 0;
}
