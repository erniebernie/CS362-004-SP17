//Ernie Bodle
//unittest2.c
//for assignment 3


#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(){

    int i;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};


    struct gameState * gs1;
    gs1 = newGame();
    initializeGame(1, k, 5, gs1);

    struct gameState * gs2;
    gs2 = newGame();
    initializeGame(2, k, 5, gs2);

    struct gameState * gs3;
    gs3 = newGame();
    initializeGame(3, k, 5, gs3);



    printf("-----------------------------\n");
    printf("Testing 1 player\n");
    printf("-----------------------------\n\n");

    for(i = 0; i < 3; i++){
	printf("Testing player %d: ", i);
	if(scoreFor(i, gs1) == 0){
	    printf("Test passed! No scores for player %d.\n", i);
	} else {
	    printf("Test failed!\n");
	}
    }


    printf("-----------------------------\n");
    printf("Testing 2 player\n");
    printf("-----------------------------\n\n");

    for(i = 0; i < 2; i++){
	printf("Testing player %d: ", i);
	if(scoreFor(i,  gs2) > 0){
	    printf("Test passed! Player %d has score.\n", i);
	} else {
	    printf("Test failed!\n");
	}
    }


    i = 2;
    printf("Testing player %d: ", i);
    if(scoreFor(i, gs2) == 0){
	    printf("Test passed! No scores for player %d.\n", i);
    } else {
	printf("Test failed!\n");
    }


    printf("-----------------------------\n");
    printf("Testing 3 player\n");
    printf("-----------------------------\n\n");

    for(i = 0; i < 3; i++){
	printf("Testing player %d: ", i);
	if(scoreFor(i, gs3) > 0){
	    printf("Test passed! Player %d has score.\n", i);
	} else {
	    printf("Test failed!\n");
	}
    }



    //decontruct game struct

    return 0;
}
