//Ernie Bodle
//randomtestcard2.c
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

    struct gameState *G = NULL;
    
    printf("---------------------------------\n");
    printf("Testing Council Room card effect.\n");
    printf("---------------------------------\n\n");

    SelectStream(2);
    PutSeed(time(NULL));

    for(i = 0; i < 2000; i++){
	G = newGame();
	initializeGame(players, k, seed, G);

	p = floor(Random() * 2); //random player
	G->deckCount[p] = floor(Random() * MAX_DECK);
	G->discardCount[p] = floor(Random() * MAX_DECK);
	G->handCount[p] = floor(Random() * MAX_HAND);

	cardEffectCouncil_room(G, p, numHandCards(G));

	free(G);
    }
    printf("Ending Council Room random testing\n");


    return 0;
}
