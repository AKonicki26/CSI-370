#include "BlackJack.h"
#include <cassert>

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
