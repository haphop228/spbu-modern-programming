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
		Node* tmp = begin;
		while (tmp != end) {
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
		std::cout<<end->value;
	}
	
	template <typename T>
	bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
		std::cout << "remove_first BEGIN\n";
		Node* tmp = begin;
		Node* item_to_remove = new Node(value);
		 do{
			if (item_to_remove->value == tmp->value){
				if (tmp == begin){
					std::cout << "1\n";
					Node* b = tmp->next;
					delete tmp;
					b = begin;
				}
				else if (tmp == end){
					std::cout << "2\n";
					Node* a = tmp->prev;
					delete tmp;
					a = end;
				}
				else{
					std::cout << "3\n";
					Node* a = tmp->prev;
					a = tmp->next;
					Node* b = tmp->next;
					delete tmp;
					b = tmp->prev;
					
				}
				
				std::cout << "remove_first END_1\n";
				return 1;
			}
			else{
				tmp = tmp->next;
			}
		} while (tmp != end);
		if (item_to_remove->value == end->value) {
			std::cout << "2\n";
			Node* a = tmp->prev;
			delete tmp;
			a = end;
			return 1;
		}
		/*
		while (tmp != end) {
			if (item_to_remove->value == tmp->value){
				if (tmp == begin){
					std::cout << "1\n";
					Node* b = tmp->next;
					b = begin;
				}
				else if (tmp == end){
					std::cout << "2\n";
					Node* a = tmp->prev;
					a = end;
				}
				else{
					std::cout << "3\n";
					Node* a = tmp->prev;
					a = tmp->next;
					Node* b = tmp->next;
					b = tmp->prev;
				}
				delete tmp;
				std::cout << "remove_first END_1\n";
				return 1;
			}
			else{
				tmp = tmp->next;
			}
		}
		*/
		std::cout << "remove_first END_0\n";
		return 0;
	}

}	