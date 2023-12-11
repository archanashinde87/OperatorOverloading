// ArithmeticOpOverloadingFractionExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric>

class Fraction
{
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator=0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
    friend Fraction operator*(const Fraction& f, int value);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(int value, const Fraction& f);
    friend std::ostream& operator<<(std::ostream& out , const Fraction& f2);
    friend std::istream& operator>>(std::istream& in,  Fraction& f2);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);

    void print() const;
};

Fraction operator*(const Fraction& f, int value)
{
    return { f.m_numerator * value, f.m_denominator };
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(int value, const Fraction& f)
{
    return f*value;
}
std::ostream& operator<<(std::ostream& out, const Fraction& f2)
{
    out << f2.m_numerator << '/' << f2.m_denominator;
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& f2)
{
    char ignore{};
    in >> f2.m_numerator  >> ignore >> f2.m_denominator;

    f2.reduce();

    return in;
}
bool operator==(const Fraction& f1, const Fraction& f2)
{
    return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator ;
}
bool operator!=(const Fraction& f1, const Fraction& f2)
{
    return !operator==(f1, f2);
}
bool operator<(const Fraction& f1, const Fraction& f2)
{
    return f1.m_numerator *f2.m_denominator < f1.m_denominator * f2.m_numerator;
}
bool operator>(const Fraction& f1, const Fraction& f2)
{
    return !operator<(f2, f1);
}
bool operator<=(const Fraction& f1, const Fraction& f2)
{
    return !operator>(f1, f2);
}
bool operator>=(const Fraction& f1, const Fraction& f2)
{
    return !operator<(f1, f2);
}

void Fraction::print() const
{
    std::cout << m_numerator << '/' << m_denominator << '\n';
}
int main()
{
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f6.print();

    Fraction f7{ 0, 6 };
    f7.print();

    Fraction f8;
    std::cout << "Enter fraction 1: ";
    std::cin >> f8;

    Fraction f9;
    std::cout << "Enter fraction 2: ";
    std::cin >> f9;

    std::cout << f8 << " * " << f9 << " is " << f8 * f9 << '\n'; // note: The result of f1 * f2 is an r-value

    Fraction f11{ 3, 2 };
    Fraction f12{ 5, 8 };

    std::cout << f11 << ((f11 == f12) ? " == " : " not == ") << f12 << '\n';
    std::cout << f11 << ((f11 != f12) ? " != " : " not != ") << f12 << '\n';
    std::cout << f11 << ((f11 < f12) ? " < " : " not < ") << f12 << '\n';
    std::cout << f11 << ((f11 > f12) ? " > " : " not > ") << f12 << '\n';
    std::cout << f11 << ((f11 <= f12) ? " <= " : " not <= ") << f12 << '\n';
    std::cout << f11 << ((f11 >= f12) ? " >= " : " not >= ") << f12 << '\n';

    return 0;
}

