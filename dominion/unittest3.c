//Ernie Bodle
//unittest3.c
//for assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(){

    int i;

    int costs[256] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 
	4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 
	5, 4, 4, 4};

    printf("-----------------------------\n");
    printf("Testing getCost\n");
    printf("-----------------------------\n\n");

    for(i = 0; i < 26; i++){
	printf("%d",i);
	if(getCost(i) != costs[i]){
	    printf("Test failed %d != %d\n", getCost(i), costs[i]);
	} else {
	    printf("Test passed %d == %d\n", getCost(i), costs[i]);
	}
    }


    return 0;
}
