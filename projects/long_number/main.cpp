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
	/*
	while (str[i] != '\0'){
		length++;
		i++;
	}
	std::cout<< std::endl << length << "length!!!";
	
	ln a(str);
	AKrivoshein::LongNumber b = str;
	AKrivoshein::LongNumber c(AKrivoshein::LongNumber ("23456"));
	ln d = "01234567891";
	ln e = ln ("865735435");
	if (a != d){
		std::cout<< "TRUE" << std::endl;
	}
	else {
		std::cout << "FALSE" << std::endl;
	}
	*/
	
	//ln a = str;
	//ln b;
	//b = AKrivoshein::LongNumber("-15");
	//ln c = "-123213213123213123123123123";
	//ln d;
	//d = b;
	
	//AKrivoshein::LongNumber one_v1 = AKrivoshein::LongNumber("1");
	//AKrivoshein::LongNumber one_v2 = AKrivoshein::LongNumber("-1");
	//AKrivoshein::LongNumber one_v3 = AKrivoshein::LongNumber("-123");
	//AKrivoshein::LongNumber x("-1");
	//std::cout << x.get_digits_number();
	AKrivoshein::LongNumber one_v4 = AKrivoshein::LongNumber("19");
	
	
	AKrivoshein::LongNumber twelve = AKrivoshein::LongNumber("9");
	//bool print = twelve < one_v1; // false
	//std::cout << print;
	//std::cout << one_v2 << "          " << one_v3 << "                    " << x;
	//std::cout << x;
	ln a = one_v4 + twelve;
	std::cout << a;
	//std::cout << a << " " << b << " " << c << " " << d << " ";
	return 0;
}