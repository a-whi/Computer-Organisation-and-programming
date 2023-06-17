#include <stdio.h> //Normal library
#include <string.h> //USed for string length stuff
#include <ctype.h> // Used for in punctuation/letter

int main(int argc, char *argv[]){

    int word_count = 0;  //word counter
    char current_word[100]; //word will be an array of 100 characters so that larger words can be analyised 

    int len_target = strlen(argv[2]);

    //Opens the file
    FILE * readfile = fopen(argv[1], "r");

    //If file not found 'error'
    if (readfile == NULL) {
        printf("file can't be opened \n");
        return 1;
    }

    // Reads the words in the file and stores it in 'word' variable
    while(fscanf(readfile,"%s",current_word)==1){

        //converts all the letters in the word to lowercase for easy comparison
        for (int i = 0; i < strlen(current_word); i++){
            current_word[i] = tolower(current_word[i]);
        }
        int word_length = strlen(current_word);
        //if word is 3 characters long && the string compare is the same
        if(word_length == len_target && strncmp(current_word,argv[2],len_target)==0){
            word_count++;
        //if word is bigger than 3 && the last character isn't a letter && the string compare for the first 3 characters is equal to bee
        }else if (word_length > len_target && !isalnum(current_word[len_target])&& strncmp(current_word,argv[2],len_target)==0){
            word_count++;
        }
    }

    printf("There were %d occurances of the word %s in the text\n", word_count, argv[2]);

    //Closes file
    fclose(readfile);

    return 0;
}
