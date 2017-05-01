//Ernie Bodle
//cardtest2.c
//for assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(){

    int i;
    int players = 2;
    int seed = 100;
    int current_player = 0;
    int handPos = 0;
    int choice = 0;

    int temphand[MAX_HAND];
    for(i = 0; i < MAX_HAND; i++){
	temphand[i] = -1; //nothing
    } 

    int inital_hand_count = 0;


    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};


    struct gameState * gs;
    gs = newGame();
    initializeGame(players, k, seed, gs);


    printf("-----------------------------\n");
    printf("Testing Adventurer card effect.\n");
    printf("-----------------------------\n\n");

    //this card should get two tresure cards from the deck

    for(i = 0; i < 5; i++){	
	printf("\nTest %d\n", i);
	
	inital_hand_count = numHandCards(gs);
	cardEffectAdventurer(gs, current_player, 0, temphand, 0, 0);
	printf("ihc == %d, numHand == %d\n", inital_hand_count, numHandCards(gs));

	if(numHandCards(gs) == (inital_hand_count + 2)){
	    printf("Test Passed! Two tresure cards were added!\n");
	} else {
	    printf("Test Failed! Two tresure cards were not added!\n");
	}
    }

    //decontruct game struct

    return 0;
}




