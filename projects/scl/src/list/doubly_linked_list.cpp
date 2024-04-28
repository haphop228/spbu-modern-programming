#include "doubly_linked_list.hpp"

namespace IBusko {
	template <typename T>
	DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
		//std::cout << "2";
		delete this->begin;
		delete this->end;
		
	}
	template <typename T>
	void DoublyLinkedList<T>::push_back(const T& value) noexcept {
		if (this->begin == nullptr) {
			this->begin = end;
			this->begin->value = value;
			this->begin->next = this->end;
			this->end->prev = begin;
		}
		else {
			T tmp = this->end->value;
			Node* new_node = nullptr;
			this->end->value = value;
			this->end->prev = new_node;
			new_node->next = this->end;
			new_node->value = tmp;
		}
	}
	template <typename T>
	void DoublyLinkedList<T>::print() const noexcept {
		Node* tmp = this->begin->next;
		while (tmp != nullptr) {
			std::cout << tmp->value;
			tmp = tmp->next;
		}
		//std::cout << "3";
	}

}	