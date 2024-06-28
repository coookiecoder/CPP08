#include <cstdlib>
#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> stack;

	for (int cursor = 0; cursor < 100; ++cursor) {
		stack.push(rand() % 10000);
	}

	for (MutantStack<int>::iterator cursor = stack.begin(); cursor != stack.end(); cursor++) {
		if (cursor + 1 != stack.end())
			std::cout << *cursor << " ";
		else
			std::cout << *cursor;
	}
}