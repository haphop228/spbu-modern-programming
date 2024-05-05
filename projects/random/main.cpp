#include <iostream>
#include "templates.cpp"
//typedef IBusko::DoublyLinkedList node;

int main() {
	//std::cout<<"Hello world!";
	IBusko::DoublyLinkedList<int> b;
	for (int i = 0; i < 10; i++){
		b.push_back(i);
	}
	//b.print();
	b.remove_first(9);
	b.print();
	//std::cout << typeid(b).name() << std::endl;
	//std::cout << typeid(a).name() << std::endl;
	//b;
	//b.push_back(a);

}