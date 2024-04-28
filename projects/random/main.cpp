#include <iostream>
#include "long_number.hpp"
#include "doubly_linked_list.hpp"

typedef AKrivoshein::LongNumber ln;
//typedef IBusko::DoublyLinkedList node;

int main() {
	char a = 10;
	IBusko::DoublyLinkedList<int> b;
	//std::cout << typeid(b).name() << std::endl;
	//std::cout << typeid(a).name() << std::endl;
	//b;
	b.push_back(a);
	b.print();
}