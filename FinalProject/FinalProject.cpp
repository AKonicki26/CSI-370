// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Test.h"
#include "BlackJack.h"
#include <Windows.h>


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