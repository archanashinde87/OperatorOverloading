// OverloadingOperatorsAndFunctionTemplates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Cents
{
	int m_cents{};

public:
	Cents(int cents)
		:m_cents{ cents }
	{}
	
	friend bool operator<(const Cents& cent1, const Cents& cent2);
	friend std::ostream& operator<<(std::ostream& out, const Cents& cent);
};

bool operator<(const Cents& cent1, const Cents& cent2)
{
	return cent1.m_cents < cent2.m_cents;
}

std::ostream& operator<<(std::ostream& out, const Cents& cent)
{
	std::cout << cent.m_cents;
	return out;
}

template<typename T>
const T& max(const T& x, const T& y)
{
	return (x < y) ? y : x;
}
int main()
{
	Cents nickel{ 5 };
	Cents dime{ 10 };

	Cents bigger{ max(nickel,dime) };
	std::cout << bigger << " is bigger.\n";

	return 0;
}

