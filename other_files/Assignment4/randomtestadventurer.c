//Ernie Bodle
//randomtestadventuere.c
//for assignment 4


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rngs.h"

int main(){

    int players = 2;
    int seed = 100;
    int p, i;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};

    struct gameState *testG = NULL;
    int z, drawntresure;

    //refacor code
    int thisPlayer = 0;
	int cardDrawn=0;

    int temphand[MAX_HAND];
    for(i = 0; i < MAX_HAND; i++){
	temphand[i] = -1; //nothing
    } 

    printf("---------------------------------\n");
    printf("Testing Adventurer card effect.\n");
    printf("---------------------------------\n\n");

    SelectStream(2);
    PutSeed(time(NULL));

    for(i = 0; i < 2000; i++){
	testG = newGame();
	initializeGame(players, k, seed, testG);

	p = floor(Random() * 2); //random player
	testG->deckCount[p] = floor(Random() * MAX_DECK);
	testG->discardCount[p] = floor(Random() * MAX_DECK);
	testG->handCount[p] = floor(Random() * MAX_HAND);
	z = floor(Random() * MAX_HAND);
	drawntresure = floor(Random() * 5);

	//cardEffectAdventurer(testG, p, 0, temphand, z, drawntresure);
		
	play_adventurer(thisPlayer, drawntresure, cardDrawn, temphand, &testG);

	free(testG);
    }
    printf("Ending Adventurer random testing\n");


    return 0;
}
