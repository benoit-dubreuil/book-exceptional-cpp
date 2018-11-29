#include <iostream>
#include "Stack/Stack.h"
#include <vector>

struct OperatorTest
{
	OperatorTest()
	{
		std::cout << "Constructor" << std::endl;
	}

	~OperatorTest()
	{
		std::cout << "Destructor" << std::endl;
	}

	OperatorTest&  operator=(const OperatorTest& other)
	{
		std::cout << "Assignment" << std::endl;
		return *this;
	}
};

int main()
{
	// Operator new[]
	OperatorTest* test1 = static_cast<OperatorTest*>(operator new[](sizeof(OperatorTest) * 5)); // Only allocate memory
	new (&test1[0]) OperatorTest(); // Calls the constructor by doing a placement new
	test1[0].~OperatorTest(); // Calls the destructor and print it
	operator delete[](test1);

	std::cout << std::endl;

	// Operator new
	OperatorTest* test2 = static_cast<OperatorTest*>(operator new(sizeof(OperatorTest) * 5)); // Only allocate memory
	new (&test2[0]) OperatorTest(); // Calls the constructor by doing a placement new
	test2[0].~OperatorTest(); // Calls the destructor and print it
	operator delete(test2);

	std::cout << std::endl;

	{
		// How does the STL allocate memory?
		std::vector<OperatorTest> test3{ 3 }; // Allocate memory and calls the default constructor
	}

	std::cout << std::endl;

	// Manual new[] / delete[]
	OperatorTest* test4 = new OperatorTest[3];
	delete[] test4;

	std::cout << std::endl;

	Stack<int> stack1{ 5 };
	Stack<int> stack2{ 7 };
	stack1 = stack2;

	Stack<int> stack3{ 3 };

	std::cout << "Stack 1 (size) : " << stack1.size() << std::endl;
	std::cout << "Stack 2 (size) : " << stack2.size() << std::endl;
	
	stack3 = std::move(stack1);

	std::cout << "Stack 3 (size) : " << stack3.size() << std::endl;

	std::cout << std::endl;

	stack3 = Stack<int>(2);
	stack3.push(42);

	std::cout << "Stack 3 (size) : " << stack3.size() << std::endl;
	std::cout << "Stack 3 (count) : " << stack3.count() << std::endl;
	std::cout << "Stack 3 (top) : " << stack3.top() << std::endl << std::endl;

	stack3.push(-3);

	std::cout << "Stack 3 (size) : " << stack3.size() << std::endl;
	std::cout << "Stack 3 (count) : " << stack3.count() << std::endl;
	std::cout << "Stack 3 (top) : " << stack3.top() << std::endl << std::endl;

	stack3.push(69);

	std::cout << "Stack 3 (size) : " << stack3.size() << std::endl;
	std::cout << "Stack 3 (count) : " << stack3.count() << std::endl;
	std::cout << "Stack 3 (top) : " << stack3.top() << std::endl;

	return 0;
}