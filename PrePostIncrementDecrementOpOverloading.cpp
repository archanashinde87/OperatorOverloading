// PrePostIncrementDecrementOpOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Digit
{
    int m_digit{};

public:
    Digit(int digit=0) : m_digit{digit}
    {}

    Digit& operator++()
    {
        if (m_digit == 9)
            m_digit = 0;
        else
            ++m_digit;

        return *this;
    }
    Digit& operator--()
    {
        if (m_digit == 0)
            m_digit = 9;
        else
            --m_digit;

        return *this;

    }
    Digit operator++(int)
    {
        Digit temp{ *this };
        ++(*this);
        return temp;
    }
    Digit operator--(int)
    {
        Digit temp{ *this };
        --(*this);
        return temp;
    }
   friend std::ostream& operator<<(std::ostream& out, const Digit& digit);

};

std::ostream& operator<<(std::ostream& out, const Digit& digit)
{
    out << digit.m_digit;
    return out;
}

int main()
{
    Digit digit{ 5 };

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}

