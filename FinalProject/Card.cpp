#include "Card.h"


char getCardValueString(Card card)
{
	switch ((int)card.value) {
	case 11:
		return 'J';
	case 12:
		return 'Q';
	case 13:
		return 'K';
	default:
		return card.value + 48;
	}
}


int getCardValue(Card card) {
	return card.value >= 10 ? 10 : card.value;
}
