#pragma once

#include "Card.h"
#include <iostream>

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
	int takeTurn();

	/// <summary>
	/// Have the dealer take their turn
	/// </summary>
	/// <returns>0 if pass, non-0 if draw card</returns>
	int dealerTurn();

	int getHandValue();

	void displayHand();
private:
	Hand mHand;
};