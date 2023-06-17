#include <stdio.h>
#include <stdlib.h> // Used for rand()
#include <stdbool.h> // Used for my while case as I use 'true'
#include <time.h> // For generating for 'truely' random

int rolldice(); // declare another function

int main(){

    int diceRolls = 0; // Counts number of rolls
    int player_winnings; 
    int first_diceTotal; // Remembers the first total of the original dice roll

    // Generates random number
    srand(time(0));

    // This calls the dice roll function
    int diceTotal = rolldice();
    printf("%d\n", diceTotal);
    first_diceTotal = diceTotal;
    diceRolls++;

    if (diceTotal == 7 || diceTotal == 11){
        player_winnings = 10;
        printf("Winner, you got: $%d, number of dice rolls: %d\n", player_winnings, diceRolls);
    }else if (diceTotal == 2 || diceTotal == 3 || diceTotal == 12){
        printf("Player has lost, number of rolls: %d\n", diceRolls);
    }else{
        while(true){
            diceTotal = rolldice();
            diceRolls++;
            printf("%d\n", diceTotal);
            if (diceTotal == first_diceTotal){
                player_winnings = 50;
                printf("Winner, you got: $%d, number of dice rolls: %d\n", player_winnings, diceRolls);
                break;
            }else if (diceTotal == 7){
                printf("Player has lost, number of rolls: %d\n", diceRolls);
                break;
            }
            }
        }
    return 0;
}

// A function that can be called to give 2 random numbers between 1-6
int rolldice(){

    int dice_1;
    int dice_2;
    int total;

    // This will give a random number between 1-6
    dice_1 = rand() % 6 +1;
    dice_2 = rand() % 6 +1;
    total = dice_1 + dice_2;

    return total;
}
