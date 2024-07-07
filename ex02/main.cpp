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

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	return 0;
}
