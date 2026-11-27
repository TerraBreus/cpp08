#include "span.hpp"
#include <iostream>

int main(void)
{
	try {
		Span test(12);
		test.addNumber(-14);
		test.addNumber(-15);
		std::cout << test.longestSpan() << std::endl;
		Span other = test;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
