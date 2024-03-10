#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	IBusko::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};

//Tests of "=="
TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}

//Tests of ">"
TEST_F(IsMoreFixture, more) {
	ASSERT_TRUE(twelve > one_v1) 
		<< "Проверка " << twelve << " > " << one_v1;
}

TEST_F(IsGreaterFixture, less) {
	ASSERT_FALSE(one_v1 > twelve) 
		<< "Проверка " << one_v1 << " > " << twelve;
}

TEST_F(IsGreaterFixture, equal) {
	ASSERT_FALSE(one_v1 > one_v1) 
		<< "Проверка " << one_v1 << " > " << one_v1;
}

TEST_F(IsGreaterFixture, less_negative_var) {
	ASSERT_FALSE(negative_twelve > one_v1) 
		<< "Проверка " << negative_twelve << " > " << one_v1;
}

TEST_F(IsGreaterFixture, equal_negative_var) {
	ASSERT_TRUE(one_v1 > negative_one) 
		<< "Проверка " << one_v1 << " > " << negative_one;
}

//Tests of "<"
TEST_F(IsLessFixture, less) {
	ASSERT_TRUE(one_v1 < twelve) 
		<< "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(IsLessFixture, more) {
	ASSERT_FALSE(twelve < one_v1) 
		<< "Проверка " << twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal) {
	ASSERT_FALSE(one_v1 < one_v1) 
		<< "Проверка " << one_v1 << " < " << one_v1;
}

TEST_F(IsLessFixture, less_negative_var) {
	ASSERT_TRUE(negative_twelve < one_v1) 
		<< "Проверка " << negative_twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal_negative_var) {
	ASSERT_FALSE(negative_one < one_v1) 
		<< "Проверка " << negative_one << " < " << one_v1;
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
