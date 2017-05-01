//Ernie Bodle
//cardtest4.c
//for assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(){

    int players = 2;
    int seed = 100;
    int current_player = 0;
    int handPos = 0;
    int choice = 0;

    int output; 
    int temphand[MAX_HAND];

    int inital_hand_count = 0;

    int i, j;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};


    struct gameState * gs;
    gs = newGame();
    initializeGame(players, k, seed, gs);


    printf("-----------------------------\n");
    printf("Testing Mine card effect.\n");
    printf("-----------------------------\n\n");


    //output should always equal -1
    printf("Output should always equal -1!\n");
    for(i = 0; i < 5; i++){
	for(j = 0; j < 5; j++){

	    output = cardEffectMine(gs, 0, 0, i, j);

    if(output != -1){
	    printf("Test failed! Output is not -1!\n");
	} else {
	    printf("Test Passed!\n");
	}
	   
	    //printf("output at (%d,%d) = %d\n", i, j, output);
	}
    }



    //decontruct game struct

    return 0;
}




