#include "Span.hpp"

#define INT_MAX 2147483647

void Span::sort() {
	for (unsigned int cursor_one = 0; cursor_one < this->actual_size; cursor_one++) {
		unsigned int min = cursor_one;
		for (unsigned int cursor_two = cursor_one; cursor_two < this->actual_size; cursor_two++) {
			if (this->data[min] > this->data[cursor_two])
				min = cursor_two;
		}
		int buffer = this->data[min];
		this->data[min] = this->data[cursor_one];
		this->data[cursor_one] = buffer;
	}
}

Span::Span() {
	throw(std::invalid_argument("cannot create a null size array"));
}

Span::Span(unsigned int size) {
	this->size = size;
	try {
		this->data = new int[size];
	} catch (std::exception &error) {
		std::cerr << "couldn't create the array" << std::endl;
		throw (error);
	}
	this->actual_size = 0;
}

Span::Span(Span &copy) {
	this->size = copy.size;
	try {
		this->data = new int[copy.size];
	} catch (std::exception &error) {
		std::cerr << "couldn't create the array" << std::endl;
		throw (error);
	}
	this->actual_size = copy.actual_size;
	for (unsigned int cursor = 0; cursor < this->actual_size; ++cursor) {
		this->data[cursor] = copy.data[cursor];
	}
}

Span::~Span() {
	delete[] this->data;
}

Span &Span::operator=(Span &copy) {
	this->size = copy.size;
	try {
		this->data = new int[copy.size];
	} catch (std::exception &error) {
		std::cerr << "couldn't create the array" << std::endl;
		throw (error);
	}
	this->actual_size = copy.actual_size;
	for (unsigned int cursor = 0; cursor < this->actual_size; ++cursor) {
		this->data[cursor] = copy.data[cursor];
	}

	return *this;
}

void Span::addNumber(int data) {
	if (actual_size == size) {
		throw (std::invalid_argument("data is already full"));
	} else {
		this->data[actual_size] = data;
		actual_size++;
	}
}

int Span::shortestSpan(void) {
	Span buffer(*this);
	buffer.sort();

	int res = INT_MAX;

	for (int* cursor = buffer.data; cursor != buffer.data + actual_size - 1; cursor++) {
		if (*(cursor + 1) - *cursor < res) {
			res = *(cursor + 1) - *cursor;
		}
	}
	return (res);
}

int Span::longestSpan(void) {
	Span buffer(*this);
	buffer.sort();

	return (buffer.data[actual_size - 1] - buffer.data[0]);
}

unsigned int Span::get_size() {
	return this->actual_size;
}

void Span::print(void) {
	for (unsigned int cursor = 0; cursor < this->get_size(); cursor++) {
		if (cursor + 1 < this->get_size())
			std::cout << this->data[cursor] << " ";
		else
			std::cout << this->data[cursor];
	}
	std::cout << std::endl;
}

int Span::operator[](unsigned int index) {
	if (index >= size || size == 0) {
		throw (std::invalid_argument("invalid index"));
	} else {
		return (this->data[index]);
	}
}