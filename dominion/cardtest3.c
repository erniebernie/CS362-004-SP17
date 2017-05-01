//Ernie Bodle
//cardtest3.c
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


	int prev_numBuy = 0;	
    int inital_hand_count = 0;

    int i;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};


    struct gameState * gs;
    gs = newGame();
    initializeGame(players, k, seed, gs);


    printf("-----------------------------\n");
    printf("Testing Council Room card effect.\n");
    printf("-----------------------------\n\n");

    //this should draw 4 cards and add to numBuys
    

    for(i = 0; i < 20; i++){	
	printf("\nTest %d\n", i);
	
	prev_numBuy = gs->numBuys;	
	inital_hand_count = numHandCards(gs);
	cardEffectCouncil_room(gs, 0, numHandCards(gs));
	printf("ihc == %d, numHand == %d\n", inital_hand_count, numHandCards(gs));
	printf("prev_numBuy == %d, numBuy == %d\n", prev_numBuy, gs->numBuys);

	if((prev_numBuy+1) == gs->numBuys){
	    printf("Test Passed! numBuys was incrimented!\n");
	} else {
	    printf("Test Failed! numBuys wasn't incrimented!\n");
	}
  
	if(numHandCards(gs) > inital_hand_count){
	    printf("Test Passed! Cards were added!\n");
	} else {
	    printf("Test Failed! Cards were not added!\n");
	}
   

    
    
    
    }


    //decontruct game struct

    return 0;
}




