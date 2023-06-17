#include <stdio.h> //Normal library
#include <string.h> //USed for string length stuff
#include <ctype.h> // Used for in punctuation/letter

typedef struct{
    char song_name[50]; // Won't hit 50 characters but might get close
    char artist[50]; // Won't hit 50 characters but might get close
    char album[50]; // Won't hit 50 characters but might get close
    int length; // Length is in seconds and that will be an integer
    int year;   // Will be an integer
    int listeners; //listeners will be a a whole number
}music_info;

int main(int argc, char *argv[]){

    // How many charachers are in each line
    char line[500];


    int num_line = 30; // assume there are always 30 lines

    //Opens the file
    FILE * readfile = fopen(argv[1], "r");

    //If file not found 'error'
    if (readfile == NULL) {
        printf("file can't be opened \n");
        return 1;
    }

    // Declaring I want to have 100 structs with the same info and the music_infor struct
    music_info song[num_line];
    int i = 0;
    // Loops till 30 (number of lines in the file) and reads the line and adds the info to the struct
    while(i < num_line && fgets(line, sizeof(line), readfile)){
        //Reads the line and adds the info to a struct
        sscanf(line, "%s %s %s %d %d %d", song[i].song_name, song[i].artist, song[i].album, &song[i].length, &song[i].year, &song[i].listeners);
        i++;
    }

    //Closes file
    fclose(readfile);

    // Find the 5 most listen to songs
    for(int i = 0; i < 5; i++){
        int max_lis = -1;
        int max_index = -1;

        for(int j = 0; j < num_line; j++){
            if (song[j].listeners > max_lis){
                max_lis = song[j].listeners;
                max_index = j;
            }
        }
        // print the song with the most listeners
        printf("%s - %s, %s (%d - %d)\n", song[max_index].song_name, song[max_index].artist, song[max_index].album, song[max_index].year, song[max_index].listeners);
        song[max_index].listeners = 0;
    }

    return 0;
}
