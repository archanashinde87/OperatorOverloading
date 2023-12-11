// OverloadingOperatorsAndFunctionTemplates2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

template <typename T>
T average(const T* myArray, int numValues)
{
    T sum{ 0 };
    for (int count{ 0 }; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

class Cents
{
private:
    int m_cents{};
public:
    Cents(int cents)
        : m_cents{ cents }
    {
    }

    Cents& operator+=(const Cents& cent)
    {
        m_cents += cent.m_cents;
        return *this;
    }
    Cents& operator/=(int num)
    {
        m_cents /= num;
        return *this;
    }
    friend std::ostream& operator<< (std::ostream& out, const Cents& cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }
};

int main()
{
    Cents centsArray[]{ Cents { 5 }, Cents { 10 }, Cents { 15 }, Cents { 14 } };
    std::cout << average(centsArray, 4) << '\n';

    return 0;
}