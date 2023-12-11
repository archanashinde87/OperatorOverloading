// ShallowCopyVsDeepCopyExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include<cstring>

class MyString
{

	char* m_data{};
	int m_length{};

public:

	// Default Constructor
	MyString(const char* source = "")
	{
		assert(source);  // make sure source isn't a null string

		// Find the length of the source string + 1 for null terminator
		m_length = std::strlen(source)+1;

		//Allocate a buffer equal to this length
		m_data = new char[m_length];

		//copy the parameter string in to our internal buffer
		for (int i{ 0 }; i < m_length; ++i)
			m_data[i] = source[i];

	}

	//Destructor
	~MyString()
	{
		// We need to deallocate our string
		delete[] m_data;
	}

	MyString(const MyString& source);

	char* getString() { return m_data; }
	int getLength() { return m_length; }
	void deepCopy(const MyString& source);
};

// Copy Constructor - m_data is just a shallow pointer copy of source.m_data, meaning they now both point to the same thing.
//MyString::MyString(const MyString& source)
//	: m_length{ source.m_length }
//	, m_data{ source.m_data }
//{
//}

void MyString::deepCopy(const MyString& source)
{
	// first we need to deallocate any value that this string is holding!
	delete[] m_data;

	// because m_length is not a pointer, we can shallow copy it
	m_length = source.m_length;

	// m_data is a pointer, so we need to deep copy it if it is non-null
	if (source.m_data)
	{
		m_data = new char[m_length];

		for (int i{ 0 }; i < m_length; ++i)
			m_data[i] = source.m_data[i];
	}
	else
		m_data = nullptr;
}

// Copy Constructor
MyString::MyString(const MyString& source)
{
	deepCopy(source);
}
int main()
{

	MyString hello{ "Hello, world!" };
	{
		MyString copy{ hello }; // use default copy constructor
	} // copy is a local variable, so it gets destroyed here.  The destructor deletes copy's string, which leaves hello with a dangling pointer

	std::cout << hello.getString() << '\n'; // this will have undefined behavior

	return 0;

}

