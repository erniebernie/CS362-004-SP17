CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


#Assignment 3 make stuff
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	
	./unittest1 &> unittestresult1.out
	gcov dominion.c >> unittestresult1.out
	cat dominion.c.gcov >> unittestresult1.out
	
	./unittest2 &> unittestresult2.out
	gcov dominion.c >> unittestresult2.out
	cat dominion.c.gcov >> unittestresult2.out
	
	./unittest3 &> unittestresult3.out
	gcov dominion.c >> unittestresult3.out
	cat dominion.c.gcov >> unittestresult3.out
	
	./unittest4 &> unittestresult4.out
	gcov dominion.c >> unittestresult4.out
	cat dominion.c.gcov >> unittestresult4.out
	
	./cardtest2 &> cardtestresult2.out
	gcov dominion.c >> cardtestresult2.out
	cat dominion.c.gcov >> cardtestresult2.out
	
	./cardtest3 &> cardtestresult3.out
	gcov dominion.c >> cardtestresult3.out
	cat dominion.c.gcov >> cardtestresult3.out
	./cardtest4 &> cardtestresult4.out
	gcov dominion.c >> cardtestresult4.out
	cat dominion.c.gcov >> cardtestresult4.out
	
	./cardtest1 &> cardtestresult1.out
	gcov dominion.c >> cardtestresult1.out
	cat dominion.c.gcov >> cardtestresult1.out

all_as3: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4


unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)


cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard all_as3

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.out *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 




