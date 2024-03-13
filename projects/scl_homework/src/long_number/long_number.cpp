#include "long_number.hpp"

namespace AKrivoshein {
	
	// ----------------------------------------------------------
	// DONE
	// ----------------------------------------------------------
	LongNumber::LongNumber() {
		numbers = new int [0];
		length = 0;
		sign = POSITIVE;
	}
	
	LongNumber::LongNumber(const char* const str) {
		int i = 0;
		length = 0;
		
		while(str[i] != '\0') {
			length++;
			i++;
		}

		//std::cout<< "FROM CLASS: " << length << std::endl;
		if (str[0] == '-') {
			sign = NEGATIVE;
		}
		else {
			sign = POSITIVE;
		}
		
		//std::cout<< "FROM CLASS: " << sign << std::endl;
		numbers = new int [length];
		for (int i = 0; i < length; i++) {
			numbers[i] = str[i];
		}
	}
	
	// ----------------------------------------------------------
	// NOT DONE
	// ----------------------------------------------------------
	LongNumber::LongNumber(const LongNumber& x) {
		length = x.length;
		sign = x.sign;
		numbers = new int[x.length];
		for (int i = 0; i < length; i++){
			numbers[i] = x.numbers[i];
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		//Create new 
		length = x.length;
		sign = x.sign;
		numbers = new int[x.length];
		for (int i = 0; i < length; i++){
			numbers[i] = x.numbers[i];
		}
		//Delete old
		x.length = 0;
		x.sign = POSITIVE;
		x.numbers = nullptr;
	}
	
	LongNumber::~LongNumber() {
		delete [] numbers;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		// TODO
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		// TODO
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		// TODO
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) const{
		// TODO
		return true;
	}
	
	bool LongNumber::operator != (const LongNumber& x) const{
		// TODO
		return true;
	}
	
	bool LongNumber::operator > (const LongNumber& x) const{
		// TODO
		return true;
	}
	
	bool LongNumber::operator < (const LongNumber& x) const{
		// TODO
		return true;
	}
	
	LongNumber LongNumber::operator + (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator - (const LongNumber& x) {
		// TODO
		LongNumber result = x;
		return result;
	}
	
	LongNumber LongNumber::operator * (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator / (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}
	
	int LongNumber::get_digits_number() const {
		return length;
	}
	
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	
	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		// TODO
		
		int length = 0;
		return length;
	}
	
	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		for (int i = 0; i < x.length; i++){
			os << char(x.numbers[i]);
		}
		return os;
	}
}
