#pragma once

#include <string>

enum TestEnum {
	NONE = 0,
	FIRST = 1,
	SECOND = 2,
	THIRD = 3
};

class Test
{
public:
	Test() {

	}

	Test(int number) {
		mNumber = number;
	}

	static void staticFunction() {
		staticValue++;
	}

	int getNumber() {
		return mNumber;
	}
	void setNumber(int number) {
		mNumber = number;
	}

	std::string getName() {
		return mName;
	}
	void setName(std::string name) {
		mName = name;
	}

	TestEnum getEnumVal() {
		return mEnumVal;
	}

	void setEnumVal(TestEnum value);
	void addToNumber(int num);
private:
	static int staticValue;
	int mNumber;
	TestEnum mEnumVal;
	std::string mName;
	
};

int Test::staticValue = 0;

