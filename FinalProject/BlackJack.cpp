#include "BlackJack.h"
#include <cassert>

void BlackJack::playGame() {
	// Step 1: Give 2 cards each to each player
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < NUMBER_OF_PLAYERS; j++) {
			mPlayers[j].dealCard(drawCard());
		}
	}

	// See README for how game is played. 

	// represents the number of players that didnt pass during their turn
	int playersWhoPlayed = 0;

	int winnerIndex = -1;

	// if there are any players who pass, end the game and display the winner
	do {

		// Clears screen for readability
		system("cls");

		// reset the count
		playersWhoPlayed = 0;

		if (mDealer.dealerTurn()) {
			mDealer.dealCard(drawCard());
			++playersWhoPlayed;

			// if dealer has 21, they have won
			if (mDealer.getHandValue() == 21) {
				winnerIndex = 0;
				break;
			}
		}

		// if a player has 21, they win by default
		for (int i = 1; i < NUMBER_OF_PLAYERS; i++) {
			if (mPlayers[i].takeTurn()) {
				mPlayers[i].dealCard(drawCard());
				++playersWhoPlayed;

				if (mPlayers[i].getHandValue() == 21) {
					winnerIndex = i;
					break;
				}
			}
		}

		if (playersWhoPlayed == 0)
			winnerIndex = processWinner();

	} while (playersWhoPlayed != 0);

	if (winnerIndex == -1)
		std::cout << "\n\nAll players busted :(\n";
	else if (winnerIndex == 0)
		std::cout << "\n\nThe dealer has won\n";
	else
		std::cout << "\n\nPlayer " << winnerIndex << " Has won\n";
}

void BlackJack::init()
{
	resetDeck();
}

void BlackJack::resetDeck()
{
	// Insert a card of every value into the deck

	std::cout << "Loading Deck...\n";

	std::vector<Card> tempCards;

	// For each suit
	for (int i = Suit::DIAMOND; i < Suit::ERROR; i++) {
		// For each card value
		for (int j = 1; j < 14; j++) {
			Card card;
			card.suit = SuitMap.at(i);
			card.value = j;
			tempCards.push_back(card);
		}
	}

	std::cout << "Shuffling Deck...\n";

	// Set n'th element access from https://stackoverflow.com/questions/20477545/element-at-index-in-a-stdset
	while (!tempCards.empty()) {
		int index = getRandomNumber(0, tempCards.size() - 1);

		Card cardToInsert = tempCards[index];

		mDeck.push_back(cardToInsert);
		tempCards.erase(tempCards.begin() + index);
	}

	std::cout << "Deck Shuffled.\n";

}

Card BlackJack::drawCard()
{
	assert(mDeck.size() > 0);

	// pop the first card from the deck and remove it
	Card card = mDeck[0];
	mDeck.erase(mDeck.begin());

	return card;
}


int BlackJack::getRandomNumber(int min, int max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

	return dist6(rng);
}

/// <summary>
/// Run logic to determine if the game should end
/// </summary>
/// <returns>Index of the winner of the game, -1 if all players busted</returns>
int BlackJack::processWinner()
{
	int highestHandValue = 0;
	int winnerIndex = -1;
	for (int i = 0; i < NUMBER_OF_PLAYERS; ++i) {
		int handValue = mPlayers[i].getHandValue();
		if (handValue >= highestHandValue && handValue <= 21) {
			highestHandValue = handValue;
			winnerIndex = i;
		}
	}

	return winnerIndex;
}
