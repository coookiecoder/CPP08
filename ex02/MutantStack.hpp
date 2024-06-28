#pragma once

#include <iostream>
#include <stack>

template <class stack_type>
class MutantStack: public std::stack<stack_type> {
	public:
		MutantStack() {
			return;
		}
		MutantStack(const MutantStack &copy) {
			*this = copy;
		}
		~MutantStack() {
			return ;
		}

		MutantStack &operator=(const MutantStack &copy) {
			this->c = copy.c;
			return *this;
		}

		typedef typename std::stack<stack_type>::container_type::iterator	iterator;

		iterator begin(void) {
			return this->c.begin();
		};
		iterator end(void) {
			return this->c.end();
		};
};