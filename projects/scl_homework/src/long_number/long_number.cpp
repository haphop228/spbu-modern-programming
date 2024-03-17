#include "long_number.hpp"

namespace AKrivoshein {
	
	// ----------------------------------------------------------
	// DONE
	// ----------------------------------------------------------
	LongNumber::LongNumber() {
		//std::cout << "Default constructor" << std::endl;
		//std::cout << "2" << std::endl;
		numbers_ = nullptr;
		length_ = 0;
		sign_ = POSITIVE;
	}
	
	LongNumber::LongNumber(const char* const str) {
		//std::cout << "Constructor with parametrs" << std::endl;
		int i = 0;
		length_ = 0;
		
		if (str[0] == '-') {
			while(str[i + 1] != '\0') {
				sign_ = NEGATIVE;
				length_++;
				i++;
			}
		}
		else {
			while(str[i] != '\0') {
				sign_ = POSITIVE;
				length_++;
				i++;
			}
		}
		//std::cout << "LENGTH: " <<length_<<std::endl;

		numbers_ = new int [length_];
		if (sign_ == NEGATIVE) {
			for (int i = 0; i < length_; i++) {
				numbers_[i] = str[i + 1] - '0'; // -'0' because of ACII 
			}
		}
		else {
			for (int i = 0; i < length_; i++) {
				numbers_[i] = str[i] - '0'; // -'0' because of ACII 
			}
		}
	}
	
	LongNumber::LongNumber(const LongNumber& x) {
	///	std::cout << "Constructor copy" << std::endl;
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		//std::cout << "Constructor move" << std::endl;
		//Create new 
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = x.numbers_;
		
		//Delete old
		x.length_ = 0;
		x.sign_ = POSITIVE;
		x.numbers_ = nullptr;
	}
	
	LongNumber::~LongNumber() {
	//	std::cout << "destructor" << std::endl;
		delete [] numbers_;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		//std::cout << "hgddgfhfhfffgfffhfhfhOperator move" << std::endl;
		int i = 0;
		length_ = 0;
		
		while(str[i] != '\0') {
			length_++;
			i++;
		}

		if (str[0] == '-') {
			sign_ = NEGATIVE;
		}
		else {
			sign_ = POSITIVE;
		}
		
		numbers_ = new int [length_];
		for (int i = 0; i < length_; i++) {
			numbers_[i] = str[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		//std::cout << "Operator copy" << std::endl;
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = new int[x.length_];
		for (int i = 0; i < length_; i++){
			numbers_[i] = x.numbers_[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
	//	std::cout << "Operator move" << std::endl;
		//Create new 
		length_ = x.length_;
		sign_ = x.sign_;
		numbers_ = x.numbers_;

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
	
	LongNumber LongNumber::operator + (const LongNumber& x) const {
		//Three variants: ++, +-, --
		
		LongNumber result;
		result.numbers_ = new int[0];
		result.length_ = 0;
		int index = 1;
		//int* interim_res = new int[index];
		int this_length_ = this->get_digits_number();
		int x_length_ = x.get_digits_number();
		int max_length_;
		int min_length_;
		int future_length = 0;
		LongNumber this_clone = *this;
		LongNumber x_clone = x;
		this_clone.sign_ = POSITIVE;
		x_clone.sign_ = POSITIVE;
		
		if (this_length_ > x_length_) {
			max_length_ = this_length_;
			min_length_ = x_length_;
		}
		else {
			max_length_ = x_length_;
		    min_length_ = this_length_;
		}
		
		int between_length_ = max_length_ - min_length_; //промежуточная длина, т.е. разница между большей длиной и меньшй
		int ind = 0;
		
		if (this->is_positive() && !x.is_positive()) { // +-
			int counter = 0;
			int* interim_res = new int[max_length_];
			for (int i = 0; i < max_length_; i++) { //Fill array with nules
				interim_res[i] = 0;
			}
			if (this_clone == x_clone) { // this == x
				result.sign_ = POSITIVE;
				result.length_ = 1;
				result.numbers_ = new int[1];
				result.numbers_[0] = 0;
				return result;
			}
			else if (this_clone < x_clone) { // abs(this) < abs(x) 
			//	std::cout << "1";
				for (int i = this_length_; i > 0; i--) {
					int num = 0;
					num = x.numbers_[x_length_ - 1 - counter] - this->numbers_[this_length_ - 1 - counter];
					//std::cout << "I: " << i << " NUM: " << num << "ENDD: " << x.numbers_[x_length_ - 1 - counter] << std::endl;
					if (num < 0) {
						num = 10 + num;
					//	std:: cout << x.numbers_[x_length_ - 1 - counter + 1] << std::endl;
						x.numbers_[x_length_ - 2 - counter] -= 1;
					//	std:: cout << x.numbers_[x_length_ - 1 - counter + 1] << std::endl;

					}
					interim_res[x_length_ - 1 - counter] = num;
					//std::cout  << "NUM: " << num <<std::endl;
					//std::cout<< "LLL: " << x_length_ - 1 - counter << std::endl; 
					future_length++;
					counter++;
				}
				
				for(int i = 0; i< between_length_; i++) {
					interim_res[i] = x.numbers_[i];
					future_length++;
				}
				result.sign_ = NEGATIVE;
			}
			else { // abs(this) > abs(x) 
				for (int i = x.length_; i > 0; i--) {
					int num = 0;
					num = this->numbers_[this->length_ - 1 - counter] - x.numbers_[x_length_ - 1 - counter];
					if (num < 0) {
						num = 10 + num;
						//std::cout  << "THIRD ITERATION: " << std::endl; 
						//this->numbers_[this_length_ - 3 - counter + 1] - 1;
						this->numbers_[this_length_ - 2 - counter] -= 1;
						//std::cout << this->numbers_[this_length_ - 3 - counter + 1] - 1<< "  INDEX: " << this_length_ - 3 - counter + 1 << std::endl;
					}
					interim_res[this_length_ - 1 - counter] = num;
					//std::cout  << "NUM: " << num <<std::endl;
					//std::cout<< "LLL: " << x_length_ - 1 - counter << std::endl; 
					//std::cout << "SHIT: " << this->numbers_[0]<< " "<< std::endl;
					future_length++;
					counter++;
				}
				
				for(int i = 0; i < between_length_; i++) {
					interim_res[i] = this->numbers_[i];
					//std::cout << "RES: " << this->numbers_[i] << " "<< std::endl;
					future_length++;
				}
				result.sign_= POSITIVE;
			}
			
			for (int i = 0; i < max_length_; i++) {
				//std::cout << interim_res[i] << " ";
				
			}
			if (interim_res[0] == 0) {
				result.length_ = future_length - 1;
				for (int i = 0; i < result.length_; i++){
					result.numbers_[i] = interim_res[i + 1];
				}
				return result;
				
			}
			else {
				result.length_ = future_length;
				result.numbers_ = interim_res;
				return result;
			}
		}
		
		
		else if (!this->is_positive() && x.is_positive()) { // -+
			
			return result;
		}
		
		if (this->is_positive() && x.is_positive()) { // ++
			result.sign_ = POSITIVE;
		}
		else if (!this->is_positive() && !x.is_positive()) { // --
			result.sign_ = NEGATIVE;
		}
		if (this->get_digits_number() >= x.get_digits_number()) { //Variant: this >= x
		    int* interim_res = new int[this->get_digits_number() + 1]; //Memory (max + 1)
			for (int i = 0; i < this->get_digits_number() + 1; i++) { //Fill array with nules
				interim_res[i] = 0;
			}
			int tmp = 0;
			for (int i = this->length_; i > 0; i--) {
				int num = 0;
				//Found num
				if (x.length_ - index <= -1) { 
					num = this->numbers_[this->length_ - index] + tmp;
				}
				else {
					num = this->numbers_[this->length_ - index] + x.numbers_[x.length_ - index] + tmp;
				}
				
				tmp = 0;
				//Fill interim_res with num
				if (num > 9 && (i - 1) <= 0) { //if num>9 and it's not last iteration
					tmp = 1;
					interim_res[index - 1] = num;
				}
				else if (num > 9) {
					tmp = 1;
					interim_res[index - 1] = num % 10;
				}
				else { //last iteration
					interim_res[index - 1] = num;
				}
				index++;
			}
			
			result.length_ = index - 1;
			result.numbers_ = new int[index - 1];
			int i = 0;
			while ((index - i) != 1) {
				result.numbers_[index - i - 2] = interim_res[i];
				i++;
			}
		}
		
		else if (this->get_digits_number() < x.get_digits_number()) { //Variant: this < x
			int* interim_res = new int[x.get_digits_number() + 1];
			for (int i = 0; i < x.get_digits_number() + 1; i++) { //Fill array with nules
				interim_res[i] = 0;
			}
			int tmp = 0;
			//Find num
			for (int i = x.length_; i > 0; i--) {
				int num = 0;
				if (this->length_ - index <= -1) {
					num = x.numbers_[x.length_ - index] + tmp;

				}
				else {
					num = x.numbers_[x.length_ - index] + this->numbers_[this->length_ - index] + tmp;
				}
				tmp = 0;
				//Fill interim_res with num
				if (num > 9 && (i - 1) <= 0) { //if num>9 and it's not last iteration
					tmp = 1;
					interim_res[index - 1] = num;
				}
				else if (num > 9) {
					tmp = 1;
					interim_res[index - 1] = num % 10;
				}
				else { //last iteration
					interim_res[index - 1] = num;
				}
				index++;
			}
			
			result.length_ = index - 1;
			result.numbers_ = new int[index - 1];
			int i = 0;
			while ((index - i) != 1) {
				result.numbers_[index - i - 2] = interim_res[i];
				i++;
			}
		}
		return result;
	}
	
	LongNumber LongNumber::operator - (const LongNumber& x) const {
		LongNumber result;
		result.numbers_ = new int[0];
		result.length_ = 0;
		
		int this_length_ = this->get_digits_number();
		int x_length_ = x.get_digits_number();
		int max_length_;
		int min_length_;
		int future_length = 0;
		
		LongNumber this_clone = *this;
		LongNumber x_clone = x;
		this_clone.sign_ = POSITIVE;
		x_clone.sign_ = POSITIVE;
		
		if (this_length_ > x_length_) {
			max_length_ = this_length_;
			min_length_ = x_length_;
		}
		else {
			max_length_ = x_length_;
		    min_length_ = this_length_;
		}
		
		int between_length_ = max_length_ - min_length_; //промежуточная длина, т.е. разница между большей длиной и меньшй
		
		//if (this->is_positive() && !x.is_positive()) { // +-
			int counter = 0;
			int* interim_res = new int[max_length_];
			for (int i = 0; i < max_length_; i++) { //Fill array with nules
				interim_res[i] = 0;
			}
			if (this_clone == x_clone) { // this == x
				result.sign_ = POSITIVE;
				result.length_ = 1;
				result.numbers_ = new int[1];
				result.numbers_[0] = 0;
				return result;
			}
			else if (this_clone < x_clone) { // abs(this) < abs(x) 
			//	std::cout << "1";
				for (int i = this_length_; i > 0; i--) {
					int num = 0;
					num = x.numbers_[x_length_ - 1 - counter] - this->numbers_[this_length_ - 1 - counter];
					//std::cout << "I: " << i << " NUM: " << num << "ENDD: " << x.numbers_[x_length_ - 1 - counter] << std::endl;
					if (num < 0) {
						num = 10 + num;
					//	std:: cout << x.numbers_[x_length_ - 1 - counter + 1] << std::endl;
						x.numbers_[x_length_ - 2 - counter] -= 1;
					//	std:: cout << x.numbers_[x_length_ - 1 - counter + 1] << std::endl;

					}
					interim_res[x_length_ - 1 - counter] = num;
					//std::cout  << "NUM: " << num <<std::endl;
					//std::cout<< "LLL: " << x_length_ - 1 - counter << std::endl; 
					future_length++;
					counter++;
				}
				
				for(int i = 0; i< between_length_; i++) {
					interim_res[i] = x.numbers_[i];
					future_length++;
				}
				result.sign_ = NEGATIVE;
			}
			else { // abs(this) > abs(x) 
				for (int i = x.length_; i > 0; i--) {
					int num = 0;
					num = this->numbers_[this->length_ - 1 - counter] - x.numbers_[x_length_ - 1 - counter];
					if (num < 0) {
						num = 10 + num;
						//std::cout  << "THIRD ITERATION: " << std::endl; 
						//this->numbers_[this_length_ - 3 - counter + 1] - 1;
						this->numbers_[this_length_ - 2 - counter] -= 1;
						//std::cout << this->numbers_[this_length_ - 3 - counter + 1] - 1<< "  INDEX: " << this_length_ - 3 - counter + 1 << std::endl;
					}
					interim_res[this_length_ - 1 - counter] = num;
					//std::cout  << "NUM: " << num <<std::endl;
					//std::cout<< "LLL: " << x_length_ - 1 - counter << std::endl; 
					//std::cout << "SHIT: " << this->numbers_[0]<< " "<< std::endl;
					future_length++;
					counter++;
				}
				
				for(int i = 0; i < between_length_; i++) {
					interim_res[i] = this->numbers_[i];
					//std::cout << "RES: " << this->numbers_[i] << " "<< std::endl;
					future_length++;
				}
				result.sign_= POSITIVE;
			}
			
			for (int i = 0; i < max_length_; i++) {
				//std::cout << interim_res[i] << " ";
				
			}
			if (interim_res[0] == 0) {
				result.length_ = future_length - 1;
				for (int i = 0; i < result.length_; i++){
					result.numbers_[i] = interim_res[i + 1];
				}
				return result;
				
			}
			else {
				result.length_ = future_length;
				result.numbers_ = interim_res;
				return result;
			}
			return result;
	}
	
	LongNumber LongNumber::operator * (const LongNumber& x) const {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator / (const LongNumber& x) const {
		// TODO
		LongNumber result;
		return result;
	}
	
	LongNumber LongNumber::operator % (const LongNumber& x) const {
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
			os << '-';
		}
		for (int i = 0; i < x.length_; i++){
			os << x.numbers_[i];
		}
		return os;
	}
}