//Ernie Bodle
//randomtestcard1.c
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
    //int current_player = 0;
    int handPos = 0;
    int choice = 0;
    int p;

    int i;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};

    PutSeed(time(NULL));

    printf("Random floored 1: %f\n", floor(Random() * 1));
    printf("Random floored 2: %f\n", floor(Random() * 2));
    printf("Random floored 100: %f\n", floor(Random() * 100));


    printf("-----------------------------\n");
    printf("Testing Smithy card effect.\n");
    printf("-----------------------------\n\n");

    struct gameState *G = NULL;
    SelectStream(2);

    for(i = 0; i < 2000; i++){
	G = newGame();
	initializeGame(players, k, seed, G);

	p = floor(Random() * 2); //random player
	//printf("p = %d\n", p);
	G->deckCount[p] = floor(Random() * MAX_DECK);
	G->discardCount[p] = floor(Random() * MAX_DECK);
	G->handCount[p] = floor(Random() * MAX_HAND);

	//printf("Inital Hand Count: %d\n", numHandCards(G));
	cardEffectSmithy(G, p, handPos, choice);
	//printf("Hand Count: %d\n\n", numHandCards(G));

	free(G);
    }
    printf("Ending Smithy random testing\n");


    return 0;
}
