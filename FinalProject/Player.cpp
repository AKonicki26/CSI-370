#include "Player.h"

/// <summary>
/// Have a player take their turn
/// </summary>
/// <returns>0 if pass, non-0 if draw card</returns>
int Player::takeTurn()
{
    printYourHandText();
    displayHand();

    // player is either at 21 or has busted. They cannot take a new card
    if (getHandValue() >= 21)
        return 0;

    printInputPrompt();
    int input = getInput();

    return input == 1 ? 1 : 0;
}

int Player::dealerTurn() {
    printDealerHandText();
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

        printCard(mHand.cards[i]);
    }
    printHandValue(getHandValue());

};