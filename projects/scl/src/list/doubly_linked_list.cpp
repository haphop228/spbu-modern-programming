#include "doubly_linked_list.hpp"

namespace IBusko {
	template <typename T>
	DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
		Node* tmp = begin;
		while(tmp != end){
			Node* next = tmp->next;  
			delete tmp;
			tmp = next;
		}
	delete end;
		
	}
	
	template <typename T>
	void DoublyLinkedList<T>::push_back(const T& value) noexcept {
		Node* tmp = new Node(value);
		//std::cout << "push_back BEGIN\n";
		if (begin == nullptr){
			begin = tmp;
			end = tmp;
			//std::cout << "1\n";
		}
		else{
			end->next = tmp;
			tmp->prev = end;
			end = tmp;
			//std::cout << "2\n";
		}
		//std::cout << "push_back END\n";
			
	}
	
	template <typename T>
	void DoublyLinkedList<T>::print() const noexcept {
		if (begin == nullptr){
			std:: cout << "List is empty\n";
		}
		else{
			Node* tmp = begin;
			while (tmp != end) {
				std::cout << tmp->value << " ";
				tmp = tmp->next;
			}
			std::cout<<end->value;
		}
	}
	
	template <typename T>
	bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
		//std::cout << "remove_first BEGIN\n";
		Node* tmp = begin;
		Node* item_to_remove = new Node(value);
		while (tmp != end) {
			//std::cout<<"IN WHILE\n";
			if (item_to_remove->value == tmp->value){
				if (tmp == begin){
					begin = begin->next;
					delete begin->prev;
					return 1;
				}
				else{
					//std::cout<<"IN IF\n";
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					//std::cout << "remove_first END_1\n";
					delete tmp;
					return 1;
				}
			}
			else{
				//std::cout<<"IN ELSE\n";
				tmp = tmp->next;
			}
		}
		if (item_to_remove->value == end->value){
			if (end == begin){ // In case if only one elem in list
				//::cout<<"IN IF END\n";
				delete tmp;
				begin = nullptr;
				end = nullptr;
				return 1;
			}
			else{
				
				end = tmp->prev;
				delete end->next;
				end->next = nullptr;
				return 1;
			}
		}
		//std::cout << "remove_first END_0\n";
		return 0;
	}
	
	template <typename T>
	std::size_t DoublyLinkedList<T>::size() const noexcept {
		std::size_t size = 0;
		if (begin == nullptr){
			return size;
		}
		else{
			Node* tmp = begin;
			while (tmp != end) {
				size++;
				tmp = tmp->next;
			}
			if (end != nullptr)
				size++;
			}
		return size;
	}
		
}	