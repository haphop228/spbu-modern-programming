#include "vector.hpp"
#include <iostream>


namespace IBusko{
	template <typename T>
	Vector<T>::~Vector() noexcept{
		delete [] arr;
		arr = nullptr;
	}
	
	template <typename T>
	void Vector<T>::push_back(const T& value) noexcept {
		if (size == capacity){
			T* new_arr = new T[capacity * 2];
			for (int i = 0; i < capacity; i++){
				new_arr[i] = arr[i];
			}
			capacity *= 2;
			arr = new_arr;
		}
		arr[size] = value;
		size++;
	}
	
	template <typename T>
	bool Vector<T>::has_item(const T& value) const noexcept {
		return 0;
	}
	
	template <typename T>
	bool Vector<T>::insert(const int position, const T& value) {
		return 0;
	}
	
	template <typename T>
	void Vector<T>::print() const noexcept {
		if (size == 0){
			std::cout<< "\nVector is empty";
		}
		else{
			std::cout<< '\n';
			for (int i = 0; i < size; i++){
				std::cout<<arr[i] << ' ';
			}
		}
	}
	
	template <typename T>
	bool Vector<T>::remove_first(const T& value) noexcept {
		return 0;
	}
	
	template <typename T>
	std::size_t Vector<T>::get_size() const noexcept {
		return size;
	}
}