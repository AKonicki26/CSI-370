#pragma once
#include <set>
#include <random>
#include <iostream>
#include "Card.h"

#define mDealer mPlayers[0]
#define NUMBER_OF_PLAYERS 2

static_assert(NUMBER_OF_PLAYERS < 5, "Too many players, The game is capped at 5 Players");
static_assert(NUMBER_OF_PLAYERS > 1, "Too few players, you need to play with SOMEONE");

class BlackJack
{
public:
	BlackJack() {
		init();
		playGame();
	}

	class Player {
	public:
		/// <summary>
		/// Deals a card into the players hand. Will error if more cards cannot be added
		/// </summary>
		/// <param name="dealtCard">The card to be added to the players hand</param>
		void dealCard(Card dealtCard) {
			// Will error if there are no more cards to deal into the hand
			mHand.cards[mHand.currentSize] = dealtCard;
			mHand.currentSize++;
		}

		/// <summary>
		/// Have a player take their turn
		/// </summary>
		/// <returns>0 if pass, non-0 if draw card</returns>
		int takeTurn() {
			
		}

		/// <summary>
		/// Have the dealer take their turn
		/// </summary>
		/// <returns>0 if pass, non-0 if draw card</returns>
		int dealerTurn() {
			// Dealer will always take a card unless their hand is valued at 16 or more
			if (getHandValue() >= 16)
				return 0;

			return 1;
		}

		int getHandValue() {
			int sum = 0;
			for (int i = 0; i < MAX_HAND_SIZE; i++) {
				sum += mHand.cards[i].value;
			}

			return sum;
		}
	private:
		Hand mHand;
	};

	void playGame() {
		// Step 1: Give 2 cards each to each player
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < NUMBER_OF_PLAYERS; j++) {
				mPlayers[j].dealCard(drawCard());
			}
		}
		// Step 2: insert 3 cards into the community cards
		for (int i = 0; i < 3; i++) {
			mCommunityCards[i] = drawCard();
		}

		// See README for how game is played. 

		if (mDealer.dealerTurn()) {
			mDealer.dealCard(drawCard());
		}

		for (int i = 1; i < NUMBER_OF_PLAYERS; i++) {
			if (mPlayers[i].takeTurn())
				mPlayers[i].dealCard(drawCard());
		}
	}
	

private:
	Card mCommunityCards[5];
	Player mPlayers[NUMBER_OF_PLAYERS]; // Starting with 2 players. Player 0 is always the dealer

	// Initializations that cannot be done on the assembly side
	void init();

	void resetDeck();

	Card drawCard();

	// Random Number generation code stolen from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c 
	int getRandomNumber(int min, int max);

	/*
	VARAIBLES TO NOT TOUCH IN ASSEMBLY
	These variables all use dynamic sizing which requires changing the offset used in assembly to access their information every time
	they, or literally any variable defined after one of these, are used or referenced. All dynamic memory variables are therefore decalred HERE
	so that all constant size memory variables will have their offsets constant, and thus can be hardcoded in the assembly side. Is this best practice? No.
	Are there functions to calculate offset that already exist? Prolly. But I am a college student, And this is why we have compilers to do these things for us.
	*/

	std::vector<Card> mDeck; 

	
};

