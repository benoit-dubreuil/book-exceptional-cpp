#include "CaseInsensitiveString.h"

bool CaseInsensitiveCharTraits::eq(char lhs, char rhs)
{
	return toupper(lhs) == toupper(rhs);
}

bool CaseInsensitiveCharTraits::lt(char lhs, char rhs)
{
	return toupper(lhs) < toupper(rhs);
}

int CaseInsensitiveCharTraits::compare(const char* s1, const char* s2, size_t n)
{
	return _memicmp(s1, s2, n);
}

const char* CaseInsensitiveCharTraits::find(const char* charPtr, size_t count, const char charToFind)
{
	const char charToFindUpped = toupper(charToFind);

	while (count-- > 0 && toupper(*charPtr) != charToFindUpped)
	{
		++charPtr;
	}

	return count >= 0 ? charPtr : nullptr;
}