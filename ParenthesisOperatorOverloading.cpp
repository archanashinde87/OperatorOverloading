// ParenthesisOperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>

class MyString
{
	std::string m_str{};

public:
	MyString(std::string_view str) :m_str{ str }
	{}
	//MyString operator()(int index, int length)
	//{
	//	return MyString{ m_str.substr(
	//		static_cast<std::string::size_type>(index),
	//		static_cast<std::string::size_type>(length)
	//		)};
	//}
	std::string_view operator()(int index, int length)
	{
		return std::string_view{ m_str }.substr(
			static_cast<std::string::size_type>(index),
			static_cast<std::string::size_type>(length)
			);
	}
	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_str;
	return out;
}

int main()
{
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;

}

