#include "Player.h"
#include <iostream>

/// <summary>
/// Have a player take their turn
/// </summary>
/// <returns>0 if pass, non-0 if draw card</returns>
int Player::takeTurn()
{
    std::cout << "Your hand:\n";
    displayHand();
    // TODO: More logic here. There are for sure things im missing but idk what they are

    // player is either at 21 or has busted. They cannot take a new card
    if (getHandValue() >= 21)
        return 0;

    int input = 0;

    std::cout << "1.\tDraw Card\n2.\tPass Turn\n";
    std::cin >> input;

    return input == 1 ? 1 : 0;
}

int Player::dealerTurn() {
    std::cout << "The dealers hand:\n";
    displayHand();
    // Dealer will always take a card unless their hand is valued at 16 or more
    if (getHandValue() >= 16)
        return 0;

    return 1;
}

int Player::getHandValue() {
    int sum = 0;
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        sum += getCardValue(mHand.cards[i]);
    }

    return sum;
}

void Player::displayHand()
{
    for (int i = 0; i < MAX_HAND_SIZE; ++i) {
        if (mHand.cards[i].value == 0)
            break;

        std::cout << getCardValueString(mHand.cards[i]) << " " << SuitSymbolsMap.at(mHand.cards[i].suit) << "\n";
    }
    std::cout << "Hand Value: " << getHandValue() << "\n\n";

};