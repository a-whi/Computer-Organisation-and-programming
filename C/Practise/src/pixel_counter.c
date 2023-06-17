#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Pixel { 
    int Red;
    int Green;
    int Blue;
};

struct Pixel Image[100][100];

int colour_counter(struct Pixel Image[100][100]){
    int  arr_count[3] = {0,0,0};

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){

            struct Pixel current_pixel = Image[i][j];
            int max = current_pixel.Red;

            if (current_pixel.Green > max){
                arr_count[1] += 1;
            }else if(current_pixel.Blue > max){
                arr_count[2] += 1;
            }else{
                arr_count[0] += 1;
            }
        }
    }
    printf("Red: %d \n Green: %d \n Blue: %d \n", arr_count[0], arr_count[1], arr_count[2]);
    return arr_count;
};


int main(){




    return 0;
}