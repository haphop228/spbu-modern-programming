#include <iostream>
#include "long_number.hpp"

typedef AKrivoshein::LongNumber ln;

int main(){
	//std::cout<<"Hello World!";
	char str[12] = "01234567891";
	/*
	for (int i = 0; i < 10; i++){
		str[i] = ;
		//std::cout<<str[i] << " ";
	}
	std::cout << std::endl;
	*/
	int length = 0;
	int i = 0;
	/*
	while (str[i] != '\0'){
		length++;
		i++;
	}
	std::cout<< std::endl << length << "length!!!";
	*/
	ln a(str);
	AKrivoshein::LongNumber b(a);
	AKrivoshein::LongNumber c(AKrivoshein::LongNumber ("23456"));

	std::cout << a << " " << b << " " << c;
	return 0;
}