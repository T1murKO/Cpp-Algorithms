#pragma once
#ifndef _MYSTRING_
#define _MYSTRING_

#include <iostream>
#include <exception>

class MyString
{
	char* str;
public:
	MyString()
	{
		str = nullptr;
	}
	MyString(const char* str)
	{
		size_t lenght = strlen(str);
		this->str = new char[lenght + 1];
		for (size_t i = 0; i < lenght; i++) {
			this->str[i] = str[i];
		}
		this->str[lenght] = '\0';
	}
	MyString(const MyString& other)
	{
		size_t lenght = mystrlen(other);
		this->str = new char[lenght + 1];

		for (size_t i = 0; i < lenght; i++) {
			this->str[i] = other.str[i];
		}
		this->str[lenght] = '\0';
	}
	~MyString() {
		delete[] this->str;
	}
	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
			delete[] this->str;
		size_t lenght = mystrlen(other);
		this->str = new char[lenght + 1];
		for (size_t i = 0; i < lenght; i++) {
			this->str[i] = other.str[i];
		}
		this->str[lenght] = '\0';
		return *this;
	}
	MyString operator + (const MyString& other)
	{
		MyString tempStr;
		size_t lenghtStr = mystrlen(*this);
		size_t lenghtOther = mystrlen(other);
		tempStr.str = new char[lenghtStr + lenghtOther + 1];

		for (size_t i = 0; i < lenghtStr; i++) {
			tempStr.str[i] = this->str[i];
		}
		for (size_t i = lenghtStr, j = 0; i < lenghtStr + lenghtOther; j++, i++) {
			tempStr.str[i] = other.str[j];
		}
		tempStr.str[lenghtStr + lenghtOther] = '\0';
		return tempStr;
	}

	char operator [] (const size_t index)
	{
		return this->str[index];
	}
	friend MyString operator+ (const char* other, const MyString& string);
	friend std::ostream& operator << (std::ostream& out, const MyString s);
	friend std::istream& operator >>(std::istream& in, MyString& s);
	friend size_t mystrlen(const MyString& string);
	friend void mystrcpy_s(MyString& dest, size_t cpySize, const MyString& source);
	friend void mystrcpy_s(MyString& dest, size_t cpySize, const char* source);
};

std::ostream& operator<< (std::ostream& out, const MyString string)
{
	out << string.str;
	return out;
}
std::istream& operator>>(std::istream& in, MyString& string)
{
	try
	{
		char buff[256];
		if (!(in.getline(buff, 256)))
			throw std::overflow_error("Erorr: too long string\n");
		size_t lenght = strlen(buff);
		string.str = new char[lenght + 1];
		string.str[lenght] = '\0';
		mystrcpy_s(string, lenght, buff);
		return in;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		in.setstate(std::istream::badbit);
		return in;
	}
}
MyString operator+ (const char* other, const MyString& string)
{
	MyString tempStr;
	size_t lenghtStr = strlen(string.str);
	size_t lenghtOther = strlen(other);
	tempStr.str = new char[lenghtStr + lenghtOther + 1];

	for (size_t i = 0; i < lenghtStr; i++) {
		tempStr.str[i] = other[i];
	}
	for (size_t i = lenghtStr, j = 0; i < lenghtStr + lenghtOther; j++, i++) {
		tempStr.str[i] = string.str[j];
	}
	tempStr.str[lenghtStr + lenghtOther] = '\0';
	return tempStr;
}
void mystrcpy_s(MyString& dest, size_t cpySize, const MyString& source)
{
	try
	{
		size_t destSize = mystrlen(dest);
		if (cpySize > destSize)
			throw std::out_of_range("Error: Out of range\n");
		for (size_t i = 0; i < destSize; i++)
		{
			dest.str[i] = source.str[i];
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}
void mystrcpy_s(MyString& dest, size_t cpySize, const char* source)
{
	try
	{
		size_t destSize = mystrlen(dest);
		if (cpySize > destSize)
			throw std::out_of_range("Error: Out of range\n");
		for (size_t i = 0; i < cpySize; i++)
		{
			dest.str[i] = source[i];
		}
		dest.str[destSize] = '\0';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}
size_t mystrlen(const MyString& string)
{
	try
	{
		if (string.str == nullptr)
			throw std::out_of_range("Erorr: out of range\n");
		size_t sizeIterator = 0;
		while (true)
		{
			if (string.str[sizeIterator] == '\0')
				return sizeIterator;
			sizeIterator++;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 0;
	}
}
#endif // _MYSTRING_
