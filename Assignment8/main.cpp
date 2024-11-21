extern "C" void asmMain();

#include <iostream>

extern "C" int getNumber();

extern "C" void printNumber(int);

int main() {
	asmMain();

	return 0;
}

int getNumber() {
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	return num;
}

void printNumber(int num) {
	std::cout << "Your number is " << num << "\n";
}