#pragma once

#include <stdexcept>
#include <algorithm>

template<class container_type> typename container_type::iterator easyfind(container_type& container, int to_find) {
	typename container_type::iterator buffer = find(container.begin(), container.end(), to_find);

	if (buffer == container.end())
		throw (std::invalid_argument("interger not found"));
	return (buffer);
}
