#include <cstdlib>
#include "Span.hpp"

int main() {
	Span buffer(10);

	buffer.addNumber(5);
	buffer.addNumber(6);
	buffer.addNumber(8);
	buffer.addNumber(1);
	buffer.addNumber(3);
	buffer.addNumber(4);
	buffer.addNumber(9);
	buffer.addNumber(7);
	buffer.addNumber(2);
	buffer.addNumber(10);

	try {
		buffer.addNumber(10);
	} catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}

	std::cout << buffer.shortestSpan() << std::endl;
	std::cout << buffer.longestSpan() << std::endl;

	Span buffer_big(10000);
	for (int cursor = 0; cursor < 10000; ++cursor) {
		buffer_big.addNumber(rand() % 100000);
	}

	std::cout << buffer_big.shortestSpan() << std::endl;
	std::cout << buffer_big.longestSpan() << std::endl;
}