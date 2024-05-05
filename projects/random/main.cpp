#include <iostream>
#include "templates.cpp"
//typedef IBusko::DoublyLinkedList node;

int main() {
	//std::cout<<"Hello world!";
	IBusko::DoublyLinkedList<int> b;
	std::size_t q;
	for (int i = 0; i < 10; i++){
		b.push_back(i);
	}
	b.size();
	q = b.size();
	std::cout<<q;
	//b.print();
	std::cout<<"\n";
	//b.remove_first(9);
	IBusko::DoublyLinkedList<int> a;
	q = a.size();
	std::cout<<q;
	/*
	for (int i = 0; i < 10; i++){
		b.remove_first(i);
		b.print();
		std::cout<<"\n";
	}
	
	std::cout<<"\nLAST PRINT:";
	b.print();
	*/
	
	//std::cout << typeid(b).name() << std::endl;
	//std::cout << typeid(a).name() << std::endl;
	//b;
	//b.push_back(a);

}