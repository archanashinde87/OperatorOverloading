// OperatorOverloadingCarClassExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
    std::string m_make{};
    std::string m_model{};

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }
        , m_model{ model }
    {}

    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend bool operator<(const Car& car1, const Car& car2);
};

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << "(" << car.m_make  << ", " << car.m_model << ")" << '\n';
    return out;
}
bool operator<(const Car& car1, const Car& car2)
{
    if (car1.m_make != car2.m_make)
        return car1.m_make < car2.m_make;
    else
        return car1.m_model < car2.m_model;
}
int main()
{
    std::vector<Car> cars
    {
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}