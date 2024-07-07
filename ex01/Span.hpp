#pragma once

#include <stdexcept>
#include <iostream>

class Span {
	private:
		unsigned int size;
		unsigned int actual_size;
		int *data;
		void sort();
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& copy);
		~Span();
		Span& operator=(Span& copy);

		void addNumber(int data);
		int shortestSpan(void);
		int longestSpan(void);

		unsigned int get_size(void);
		void print(void);

		int operator[](unsigned int index);
};
