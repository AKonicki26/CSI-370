#include <map>
enum Suit : short {
	DIAMOND = 0,
	HEART,
	CLUB,
	SPADE,
	ERROR
};

struct Card {
	char value;
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

struct Hand {
	Card cards[2];
	HandType type;
	char highCard;
	short currentSize = 0;
};

std::map<int, Suit> SuitMap{
	{Suit::DIAMOND, Suit::DIAMOND},
	{Suit::HEART, Suit::HEART},
	{Suit::CLUB, Suit::CLUB},
	{Suit::SPADE, Suit::SPADE}
};