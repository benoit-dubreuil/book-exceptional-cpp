#include <iostream>

#include "CaseInsensitiveString.h"

int main()
{
	CaseInsensitiveString str1 = "AaBbCc";
	CaseInsensitiveString str2 = "aAbBcC";

	std::cout << "Case insensitive string 1 : " << str1.c_str() << std::endl;
	std::cout << "Case insensitive string 2 : " << str2.c_str() << std::endl;
	std::cout << "Equals : " << (str1 == str2) << std::endl;
	std::cout << "True : " << true << std::endl;
	std::cout << "Fasle : " << false << std::endl;

	return 0;
}