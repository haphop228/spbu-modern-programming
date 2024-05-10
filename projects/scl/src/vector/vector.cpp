#include "vector.hpp"
#include <iostream>


namespace IBusko{

	template <typename T>
	Vector<T>::~Vector() noexcept{
		std::cout<<"Delete has started\n";
		delete [] this->arr;
		
		arr = nullptr;
		std::cout<<"Arr deleted";
	}
}