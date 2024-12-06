#include "Card.h"

std::string getCardValueString(Card card)
{
	switch ((int)card.value) {
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	default:
		return std::to_string((int)card.value);
	}
}

int getCardValue(Card card) {
	return card.value >= 10 ? 10 : card.value;
}