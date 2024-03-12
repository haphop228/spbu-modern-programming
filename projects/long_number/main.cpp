#include <iostream>
#include "long_number.hpp"

int main(){
	//std::cout<<"Hello World!";
	char str[12] = "0123456789";
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
	IBusko::LongNumber a(str);
	std::cout << a;
	return 0;
}