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
	AKrivoshein::LongNumber b = str;
	AKrivoshein::LongNumber c(AKrivoshein::LongNumber ("23456"));
	ln d = a;
	ln e = ln ("865735435");
	if (a == c){
		std::cout<< "TRUE" << std::endl;
	}
	else {
		std::cout << "FALSE" << std::endl;
	}
	
	std::cout << a << " " << b << " " << c << " " << d << " " << e;
	return 0;
}