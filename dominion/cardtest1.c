//Ernie Bodle
//cardtest1.c
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


    int inital_hand_count = 0;

    int i;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};


    struct gameState * gs;
    gs = newGame();
    initializeGame(players, k, seed, gs);


    printf("-----------------------------\n");
    printf("Testing Smithy card effect.\n");
    printf("-----------------------------\n\n");

    //so this card effect should let me gain 3 cards 
    //but also discard smithy
    for(i = 0; i < 100; i++){ 
	inital_hand_count = numHandCards(gs);
	cardEffectSmithy(gs, current_player, handPos, choice);

	printf("Test %d\n", i);
	printf("ihc == %d, numHand == %d\n", inital_hand_count, numHandCards(gs));
	if(numHandCards(gs) != (inital_hand_count + 2)){
	    printf("Test failed! Did not gain a next of two cards!\n");
	} else {
	    printf("Test Passed! Gained a net of two cards!\n");
	}
    }



    //decontruct game struct

    return 0;
}
