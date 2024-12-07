#pragma once
#include <set>
#include <random>
#include <iostream>
#include "Player.h"

#define mDealer mPlayers[0]
#define NUMBER_OF_PLAYERS 2

static_assert(NUMBER_OF_PLAYERS < 5, "Too many players, The game is capped at 5 Players");
static_assert(NUMBER_OF_PLAYERS > 1, "Too few players, you need to play with SOMEONE");

class BlackJack
{
public:
	BlackJack() {
		init();
	}

	void playGame();


private:
	Player mPlayers[NUMBER_OF_PLAYERS]; // Starting with 2 players. Player 0 is always the dealer

	// Initializations that cannot be done on the assembly side
	void init();

	void resetDeck();

	Card drawCard();

	// Random Number generation code stolen from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c 
	int getRandomNumber(int min, int max);

	int processWinner();

	/*
	VARAIBLES TO NOT TOUCH IN ASSEMBLY
	These variables all use dynamic sizing which requires changing the offset used in assembly to access their information every time
	they, or literally any variable defined after one of these, are used or referenced. All dynamic memory variables are therefore decalred HERE
	so that all constant size memory variables will have their offsets constant, and thus can be hardcoded in the assembly side. Is this best practice? No.
	Are there functions to calculate offset that already exist? Prolly. But I am a college student, And this is why we have compilers to do these things for us.
	*/

	std::vector<Card> mDeck;
};