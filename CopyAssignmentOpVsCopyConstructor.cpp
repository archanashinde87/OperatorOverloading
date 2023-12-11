// CopyAssignmentOpVsCopyConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cassert>

class Fraction
{
private:

   int m_numerator{0};
   int m_denominator{1};

public:

    // Defalt Constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    // Copy Constructor
    Fraction(const Fraction& copy)
        :m_numerator{ copy.m_numerator }
        , m_denominator{ copy.m_denominator }
    {
        // no need to check for a denominator of 0 here since copy must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    // overloaded assignment operator
    Fraction& operator=(const Fraction& fraction);

    // overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

};

Fraction& Fraction::operator=(const Fraction& fraction)
{
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

int main()
{
    Fraction fiveThirds{ 5, 3 };
    Fraction f;
    f = fiveThirds; // calls overloaded assignment
    std::cout << f;

    return 0;
}

