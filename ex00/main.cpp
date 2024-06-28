#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void) {
	int buffer[10] = {0,1,2,3,4,5,6,7,8,9};

	std::vector<int> vector_buffer(buffer, buffer + 10);
	std::vector<int>::iterator vector_buffer_iterator;

	try {
		vector_buffer_iterator = easyfind(vector_buffer, 5);
		
		std::cout << "found the number at the posittion : " << static_cast<int>(vector_buffer_iterator - vector_buffer.begin()) << std::endl;
	} catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		easyfind(vector_buffer, 15);

		std::cout << "found the number at the posittion : " << static_cast<int>(vector_buffer_iterator - vector_buffer.begin()) << std::endl;
	} catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
}
