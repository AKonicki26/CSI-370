#pragma once﻿

#include <map>
#include <string>

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

#define MAX_HAND_SIZE 9

struct Hand {
	Card cards[MAX_HAND_SIZE];
	short currentSize = 0;
};

const std::map<int, Suit> SuitMap = {
	{Suit::DIAMOND, Suit::DIAMOND},
	{Suit::HEART, Suit::HEART},
	{Suit::CLUB, Suit::CLUB},
	{Suit::SPADE, Suit::SPADE}
};

const std::map<Suit, std::string> SuitSymbolsMap = {
	{Suit::DIAMOND, "Diamond"},
	{Suit::HEART, "Heart"},
	{Suit::CLUB, "Club"},
	{Suit::SPADE, "Spade"}
};

char getCardValueString(Card card);

int getCardValue(Card card);