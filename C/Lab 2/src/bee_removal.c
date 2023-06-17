#include <stdio.h> //Normal library
#include <string.h> //USed for string length stuff
#include <ctype.h> // Used for in punctuation/letter

int main(){

    char bee[] = "bee"; //bee is the word we are finding
    char word[100]; //word will be an array of 100 characters so that larger words can be analyised 
    char allowed_words[100000]; //Words that aren't 'bee'

    FILE * file_bee = fopen("data/bee_movie_script.txt", "r");
    
    //If file not found 'error'
    if (file_bee == NULL) {
        printf("file can't be opened \n");
        return 1;
    }

    FILE * new_file = fopen("data/nobees.txt", "w");

    //If file not found 'error'
    if (new_file == NULL) {
        printf("file can't be created\n");
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
            continue;
        //if word is bigger than 3 && the last character isn't a letter && the string compare for the first 3 characters is equal to bee
        }else if (strlen(word) > 3 && !isalnum(word[3])&& strncmp(word,bee,3)==0){
            continue;
        }else{
            //Stores the word to allowed words array 
            strcat(allowed_words, word);
            //Adds a space inbetween the words
            strcat(allowed_words, " ");
        }
    }

    // Puts allowed_words into a new file
    fputs(allowed_words, new_file);

    //Closes file
    fclose(file_bee);
    fclose(new_file);
    return 0;
}