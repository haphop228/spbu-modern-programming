#include <iostream>
#include "long_number.hpp"

typedef AKrivoshein::LongNumber ln;

int main(){
	//std::cout<<"Hello World!";
	char str[12] = "-1234567891";
	/*
	for (int i = 0; i < 10; i++){
		str[i] = ;
		//std::cout<<str[i] << " ";
	}
	std::cout << std::endl;
	*/
	int length = 0;
	int i = 0;
	
	//AKrivoshein::LongNumber one_v4 = AKrivoshein::LongNumber("-1");
	ln a("-1234");
	ln b("321");
	ln c = a - b;
	std::cout << c;
	//int x(5);
	//int x = 5;
	
	
	//AKrivoshein::LongNumber twelve = AKrivoshein::LongNumber("-12");
	//bool print = twelve < one_v1; // false
	//std::cout << print;
	//std::cout << one_v2 << "          " << one_v3 << "                    " << x;
	//std::cout << x;
	//ln a = one_v4 + twelve;
	//std::cout << a;
	//std::cout << a << " " << b << " " << c << " " << d << " ";
	return 0;
}