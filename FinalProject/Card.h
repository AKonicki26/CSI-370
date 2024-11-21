#include <map>
enum Suit : short {
	DIAMOND = 0,
	HEART,
	CLUB,
	SPADE,
	ERROR
};

struct Card {
	// value of the card, if 0, it doesnt exist
	char value = 0;
	Suit suit;
};

enum HandType : short {
	ROYAL_FLUSH = 1,
	STRIGHT_FLUSH,
	FOUR_OF_A_KIND,
	FULL_HOUSE,
	FLUSH,
	STRAIGHT,
	THREE_OF_A_KIND,
	TWO_PAIR,
	ONE_PAIR,
	HIGH_CARD
};

#define MAX_HAND_SIZE 9

struct Hand {
	Card cards[MAX_HAND_SIZE];
	HandType type = HIGH_CARD;
	char highCardValue;
	short currentSize = 0;
};


const std::map<int, Suit> SuitMap = {
	{Suit::DIAMOND, Suit::DIAMOND},
	{Suit::HEART, Suit::HEART},
	{Suit::CLUB, Suit::CLUB},
	{Suit::SPADE, Suit::SPADE}
};