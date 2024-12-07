// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BlackJack.h"
#include <Windows.h>

extern "C" void printYourHandText() {
    std::cout << "Your Hand:\n";
}

extern "C" void printDealerHandText() {
    std::cout << "The dealers hand:\n";
}

extern "C" void printInputPrompt() {
    std::cout << "1.\tDraw Card\n2.\tPass Turn\n";
}

extern "C" int getInput() {
    int input = 0;
    std::cin >> input;
    return input;
}

extern "C" void printCard(Card card) {
    if (card.value == 0)
        return;
    std::cout << getCardValueString(card) << " " << SuitSymbolsMap.at(card.suit) << "\n";
}

extern "C" void printHandValue(int handValue) {
    std::cout << "Hand Value: " << handValue << "\n\n";
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);

    BlackJack game;

    game.playGame();

    std::cout << "Game Over\n";
}

// Old main playground
/*
int main()
{
    std::cout << "Hello World!\n";

    Test test;

    test = Test(5);

    test.setName("Woah");

    std::cout << test.getName() << "\n";

    test.setNumber(12);

    Test::staticFunction();

    test.setEnumVal(TestEnum::FIRST);
    test.getEnumVal();


    std::cout << (test.getEnumVal() != TestEnum::FIRST ? "Not " : "") << "Equal\n";

    test.addToNumber(5);

    std::cout << test.getNumber() << "\n"; // If this prints 17, the masm linking worked

}

*/