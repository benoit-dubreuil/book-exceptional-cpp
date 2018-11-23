#include "FixedVector.h"

int main()
{
	FixedVector<char, 4> v;
	FixedVector<int, 4> w;
	FixedVector<int, 4> w2(w); // Calls implicit copy constructor
	
	FixedVector<int, 4> w3(v); // Calls templated conversion constructor
	
	w = w2; // calls implicit copy assignment operator
	w = v; // calls templated assignment operator

	return 0;
}