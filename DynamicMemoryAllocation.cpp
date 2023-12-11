// DynamicMemoryAllocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<cstddef>
#include<algorithm>

std::size_t getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t count{};
    std::cin >> count;
    return count;
}

void getNames(std::string* names, size_t length)
{
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << "Eneter name#" << index + 1 << ": ";
        std::getline(std::cin >>std::ws, names[index]);
    }
}

void printNames(std::string* names, std::size_t length)
{
    std::cout << "\nHere is your sorted list:\n";

    for (std::size_t i{ 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main()
{
    std::size_t length{ getNameCount() };

    auto* names{ new std::string[length]{} };
    getNames(names, length);

    std::sort(names, names + length);

    printNames(names, length);

    return 0;
}

