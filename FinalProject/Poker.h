#pragma once
#include <set>
#include <map>
#include <random>
#include <iostream>
#include "Card.h"

#define mDealer mPlayers[0]
#define NUMBER_OF_PLAYERS 2

class Poker
{
public:
	Poker() {
		init();
	}

	class Player {
	public:
		void dealCard(Card dealtCard) {
			// Will error if there are no more cards to deal into the hand
			mHand.cards[mHand.currentSize] = dealtCard;
			mHand.currentSize++;
		}
	private:
		Hand mHand;
	};

	void playGame() {
		// Step 1: Give 2 cards each to each player
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < NUMBER_OF_PLAYERS; j++) {
				Card dealtCard = drawCard();
				mPlayers[j].dealCard(dealtCard);
			}

		// Step 2: insert 3 cards into the community cards

	}
	

private:
	Card mCommunityCards[5];
	Player mPlayers[NUMBER_OF_PLAYERS]; // Starting with 2 players. Player 0 is always the dealer

	/*
	VARAIBLES TO NOT TOUCH IN ASSEMBLY
	These variables all use dynamic sizing which requires changing the offset used in assembly to access their information every time 
	they, or literally any variable defined after one of these, are used or referenced. All dynamic memory variables are therefore decalred HERE 
	so that all constant size memory variables will have their offsets constant, and thus can be hardcoded in the assembly side. Is this best practice? No. 
	Are there functions to calculate offset that already exist? Prolly. But I am a college student, And this is why we have compilers to do these things for us. 
	*/

	// Initializations that cannot be done on the assembly side
	void init() {
		resetDeck();
	}

	void resetDeck() {
		// Insert a card of every value into the deck

		std::cout << "Loading Deck...\n";

		std::set<Card> tempCards;

		// For each suit
		for (int i = Suit::DIAMOND; i < Suit::ERROR; i++) {
			// For each card value
			for (int j = 1; j < 14; j++) {
				Card card;
				card.suit = SuitMap[i];
				card.value = j;
				tempCards.insert(card);
			}
		}

		std::cout << "Shuffling Deck...\n";

		// Set n'th element access from https://stackoverflow.com/questions/20477545/element-at-index-in-a-stdset
		while (!tempCards.empty()) {
			int index = getRandomNumber(0, tempCards.size() - 1);

			auto it = tempCards.begin();
			std::advance(it, index);
			
			Card cardToInsert = *it;

			mDeck.push_back(cardToInsert);
		}

		std::cout << "Deck Shuffled.\n";
		
	}

	Card drawCard() {

	}

	// Random Number generation code stolen from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c 
	int getRandomNumber(int min, int max) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); 

		return dist6(rng);
	}

	std::vector<Card> mDeck; 


};

