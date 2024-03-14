#include "long_number.hpp"

namespace AKrivoshein {
	
	// ----------------------------------------------------------
	// DONE
	// ----------------------------------------------------------
	LongNumber::LongNumber() {
		//std::cout << "2" << std::endl;
		numbers_ = new int [0];
		length_ = 0;
		sign_ = POSITIVE;
	}
	
	LongNumber::LongNumber(const char* const str) {
		//std::cout << "Constructor with parametrs" << std::endl;
		int i = 0;
		length_ = 0;
		
		if (str[0] == '-') {
			while(str[i + 1] != '\0') {
				//std::cout<<char(str[i + 1]) << " ";
				sign_ = NEGATIVE;
				length_++;
				i++;
			}
		}
		else {
			while(str[i] != '\0') {
				//std::cout<< char(str[i]) << " ";
				sign_ = POSITIVE;
				length_++;
				i++;
			}
		}
		
		/*
		if (str[0] == '-') {
			sign_ = NEGATIVE;
		}
		else {
			sign_ = POSITIVE;
		}
		*/
		//std::cout << "" << std::endl;

		//std::cout<< "FROM CWP sign: " << sign_ << std::endl;
		//std::cout<< "FROM CWP length: " << length_ << std::endl;
		//std::cout<< std::endl;
		//std::cout<< "FROM CLASS: " << sign << std::endl;
		numbers_ = new int [length_];
		if (sign_ == NEGATIVE) {
			for (int i = 0; i < length_; i++) {
				//std::cout << "in FOR" << std::endl;
				numbers_[i] = str[i + 1] - 48; // -48 because of ACII 
			}
		}
		else {
			for (int i = 0; i < length_; i++) {
				//std::cout << "in FOR" << std::endl;
				numbers_[i] = str[i] - 48; // -48 because of ACII 
			}
		}
	}
	
	LongNumber::LongNumber(const LongNumber& x) {
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		//Create new 
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
		//Delete old
		x.length_ = 0;
		x.sign_ = POSITIVE;
		x.numbers_ = nullptr;
	}
	
	LongNumber::~LongNumber() {
		delete [] numbers_;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		int i = 0;
		length_ = 0;
		
		while(str[i] != '\0') {
			length_++;
			i++;
		}

		//std::cout<< "FROM CLASS: " << length << std::endl;
		if (str[0] == '-') {
			sign_ = NEGATIVE;
		}
		else {
			sign_ = POSITIVE;
		}
		
		//std::cout<< "FROM CLASS: " << sign << std::endl;
		numbers_ = new int [length_];
		for (int i = 0; i < length_; i++) {
			numbers_[i] = str[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		//Create new 
		//std::cout << "2" << std::endl;
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
		//Delete old
		x.length_ = 0;
		x.sign_ = POSITIVE;
		x.numbers_ = nullptr;
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) const {
		if (sign_ != x.sign_) {
			return false;
		}
		else if (length_ != x.length_){
			return false;
		}
		else {
			if (length_ >= x.length_){
				for (int i = 0; i < length_; i++){
					if (numbers_[i] != x.numbers_[i]){
						return false;
					}
				}
			}
			else { 
				for (int i = 0; i < x.length_; i++){
					if (numbers_[i] != x.numbers_[i]){
						return false;
					} 
				}
			}
		}
		return true;
	}
	
	bool LongNumber::operator != (const LongNumber& x) const {
		if (sign_ != x.sign_) {
			return true;
		}
		else if (length_ != x.length_) {
			return true;
		}
		else { 
			if (length_ >= x.length_) {
				for (int i = 0; i < length_; i++){
					if (numbers_[i] != x.numbers_[i]) {
						return true;
					}
				}
			}
			else { 
				for (int i = 0; i < x.length_; i++) {
					if (numbers_[i] != x.numbers_[i]) {
						return true;
					} 
				}
			}
		}
		return false;
	}
	
	bool LongNumber::operator > (const LongNumber& x) const {
		//Firstly, check sign_
		if (this->sign_ > x.sign_) {
			return true;
		}
		else if (this->sign_ < x.sign_) {
			return false;
		}
		
		//Secondly, check length_
		if (this->length_ > x.length_) {
			return true;
		}
		else if (this->length_ < x.length_) {
			return false;
		}
		
		//Thirdly, check numbers_
		for (int i = 0; i < length_; i++) {
			if (this->numbers_[i] > x.numbers_[i]) {
				return true;
			}
			else if (this->numbers_[i] == x.numbers_[i]) {
				continue;
			}
			else {
				return false;
			}
		}

		//Lastly, if equal
		return false;
	}
		
	bool LongNumber::operator < (const LongNumber& x) const {
		//Firstly, check sign_
		if (this->sign_ < x.sign_) {
			return true;
		}
		else if (this->sign_ > x.sign_) {
			return false;
		}
		
		//Secondly, check length_
		if (this->length_ < x.length_) {
			return true;
		}
		else if (this->length_ > x.length_) {
			return false;
		}
		
		//Thirdly, check numbers_
		for (int i = 0; i < length_; i++) {
			if (this->numbers_[i] < x.numbers_[i]) {
				return true;
			}
			else if (this->numbers_[i] == x.numbers_[i]) {
				continue;
			}
			else {
				return false;
			}
		}

		//Lastly, if equal
		return false;
	}	
	
	// ----------------------------------------------------------
	// NOT DONE
	// ----------------------------------------------------------
	
	LongNumber LongNumber::operator + (const LongNumber& x) {
		//Three variants: ++, +-, --
		

		LongNumber result;
		result.numbers_ = new int[0];
		result.length_ = 0;
		int index = 1;
		int* interim_res = new int[index];
		
		if (this->is_positive() && x.is_positive()) { // ++
			result.sign_ = POSITIVE;
			if (this->get_digits_number() >= x.get_digits_number()) {
				int tmp = 0;
				//std::cout << "" << std::endl;
				//std::cout << "IN THE ++" << std::endl;
				for (int i = this->length_; i > 0; i--) {
					//interim_res[index - 1] = this->numbers_[i] + x.numbers_[i];
					//int tmp = 0;
					int num = 0;
					if (x.length_ - index <= -1) {
						num = this->numbers_[this->length_ - index] + tmp;
						//std::cout << "IN IF" << std::endl;

					}
					else {
						num = this->numbers_[this->length_ - index] + x.numbers_[x.length_ - index] + tmp;
						//std::cout << "IN ELSE" << std::endl;
					}
					//std::cout <<  " (this->length_ - index): " << this->length_ - index << " (x.length_ - index): " << x.length_ - index << std::endl;
					tmp = 0;
					//std::cout  << "this->length_: " <<  this->length_  << " x.length_: " <<  x.length_ << std::endl;
					//std::cout << "num: " << num << std::endl;
					//std::cout << "this->numbers_[i] " << this->numbers_[this->length_ - index] << std::endl;
					//std::cout << "x.numbers_[i] " << x.numbers_[x.length_ - index] <<  std::endl;
					if (num > 9) {
						tmp = 1;
						interim_res[index - 1] = num % 10;
						//std::cout <<  "interim_res[index - 1]: " << interim_res[index - 1] << std::endl;
					}
					else {
						interim_res[index - 1] = num;
						//std::cout <<  "interim_res[index - 1]: " << interim_res[index - 1] << std::endl;
						//std::cout << "IN THE num <= 9" << std::endl;
					}
					//result.numbers_[index] = 
					
					index++;
					//std::cout << "INDEX:" << index << std::endl;
				}
				
				result.length_ = index - 1;
				result.numbers_ = new int[index - 1];
				int i = 0;
				while ((index - i) != 1) {
					result.numbers_[index - i - 2] = interim_res[i];
					//std::cout << "IN WHILE ID+EXEF: " << char(interim_res[i])  << " LOL "<< std::endl;
					//std::cout<<result.numbers_[index - i] << std::endl;
					i++;
				}
				/*
				for (int i = 0; i < index; i++) {
					std::cout << char(interim_res[i]) << " ";
				}
				*/
				
			}
			else {
				
			}
		}
		else if (this->is_positive() && !x.is_positive()) { // +-
			
		}
		else { // --
			
		}
		
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
		return length_;
	}
	
	bool LongNumber::is_positive() const {
		return sign_ == POSITIVE;
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
		if (!x.is_positive()){
			//std::cout << " asdadsad" << std::endl;
			os << '-';
		}
		for (int i = 0; i < x.length_; i++){
			os << x.numbers_[i];
		}
		return os;
	}
}