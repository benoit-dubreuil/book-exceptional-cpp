#pragma once

#include <string>

struct CaseInsensitiveCharTraits : public std::char_traits<char>
{
	static bool eq(char lhs, char rhs);
	static bool lt(char lhs, char rhs);
	static int compare(const char* s1, const char* s2, size_t n);
	static const char* find(const char* charPtr, size_t count, const char charToFind);
};

using CaseInsensitiveString = std::basic_string<char, CaseInsensitiveCharTraits>;