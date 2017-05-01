//Ernie Bodle
//unittest4.c
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
    initializeGame(2, k, 5, gs1);

    struct gameState * gs2;
    gs2 = newGame();
    initializeGame(3, k, 5, gs2);

    struct gameState * gs3;
    gs3 = newGame();
    initializeGame(4, k, 5, gs3);



    printf("-----------------------------\n");
    printf("Testing endTurn()\n");
    printf("-----------------------------\n\n");

    printf("Testing %d players\n", gs1->numPlayers);
    for(i = 0; i < 10; i++){
	
	if(whoseTurn(gs1) == i%gs1->numPlayers){
	    printf("Test passed! Turn is player %d's turn!\n", i%gs1->numPlayers);
	} else {
	    printf("Test failed! Turn is not %d's turn!\n", i%gs1->numPlayers);
	}

	printf("Ending turn!\n");
	endTurn(gs1);
    }

    printf("Testing %d players\n", gs2->numPlayers);
    for(i = 0; i < 10; i++){
	
	if(whoseTurn(gs2) == i%gs2->numPlayers){
	    printf("Test passed! Turn is player %d's turn!\n", i%gs2->numPlayers);
	} else {
	    printf("Test failed! Turn is not %d's turn!\n", i%gs2->numPlayers);
	}

	printf("Ending turn!\n");
	endTurn(gs2);
    }

    printf("Testing %d players\n", gs3->numPlayers);
    for(i = 0; i < 10; i++){
	
	if(whoseTurn(gs3) == i%gs3->numPlayers){
	    printf("Test passed! Turn is player %d's turn!\n", i%gs3->numPlayers);
	} else {
	    printf("Test failed! Turn is not %d's turn!\n", i%gs3->numPlayers);
	}

	printf("Ending turn!\n");
	endTurn(gs3);
    }
    
    
    //decontruct game struct

    return 0;
}
