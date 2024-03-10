#include <gtest/gtest.h>

#include "long_number.hpp"

{
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

//Tests of "=="
class EqualityFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
};
TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFix ture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}

//Tests of ">"
class IsMoreFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};

TEST_F(IsMoreFixture, more) {
	ASSERT_TRUE(twelve > one_v1) 
		<< "Проверка " << twelve << " > " << one_v1;
}

TEST_F(IsGreaterFixture, less) {
	ASSERT_FALSE(one_v1 > twelve) 
		<< "Проверка " << one_v1 << " > " << twelve;
}

TEST_F(IsGreaterFixture, equal) {
	ASSERT_FALSE(one_v1 > one_v2) 
		<< "Проверка " << one_v1 << " > " << one_v2;
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
class IsLessFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};

TEST_F(IsLessFixture, less) {
	ASSERT_TRUE(one_v1 < twelve) 
		<< "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(IsLessFixture, more) {
	ASSERT_FALSE(twelve < one_v1) 
		<< "Проверка " << twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal) {
	ASSERT_FALSE(one_v1 < one_v2) 
		<< "Проверка " << one_v1 << " < " << one_v2;
}

TEST_F(IsLessFixture, less_negative_var) {
	ASSERT_TRUE(negative_twelve < one_v1) 
		<< "Проверка " << negative_twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal_negative_var) {
	ASSERT_FALSE(negative_one < one_v1) 
		<< "Проверка " << negative_one << " < " << one_v1;
}

//Tests of "+"
class Addition : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
		IBusko::LongNumber big_num_v1 = IBusko::LongNumber("10000000000000000000");
		IBusko::LongNumber big_num_v2 = IBusko::LongNumber("6666666666666666666666");
};

TEST_F(Addition, same_nums) {
	IBusko::LongNumber ans = IBusko::LongNumber("2");
	IBusko::LongNumber res;
	res = one_v1 + one_v2;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << one_v1 << " + " << one_v2;
}

TEST_F(Addition, big_nums) {
	IBusko::LongNumber ans = IBusko::LongNumber("6676666666666666666666");
	IBusko::LongNumber res;
	res = big_num_v1 + big_num_v2;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << big_num_v1 << " + " << big_num_v2;
}

TEST_F(Addition, negative_nums) {
	IBusko::LongNumber ans = IBusko::LongNumber("-13");
	IBusko::LongNumber res;
	res = negative_one + negative_twelve;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << negative_one << " + " << negative_twelve;
}

//Tests of "-"
class Subtraction : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
		IBusko::LongNumber big_num_v1 = IBusko::LongNumber("10000000000000000000");
		IBusko::LongNumber big_num_v2 = IBusko::LongNumber("6666666666666666666666");
};

TEST_F(Subtraction, little_nums) {
	IBusko::LongNumber ans = IBusko::LongNumber("11");
	IBusko::LongNumber res;
	res = twelve - one_v1;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << twelve << " - " << one_v1;
}

TEST_F(Subtraction, null) {
	IBusko::LongNumber ans = IBusko::LongNumber("0");
	IBusko::LongNumber res;
	res = one_v1 - one_v2;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << one_v1 << " - " << one_v2;
}

TEST_F(Subtraction, big_nums) {
	IBusko::LongNumber ans = IBusko::LongNumber("6656666666666666666666");
	IBusko::LongNumber res;
	res = big_num_v2 - big_num_v1;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << big_num_v2 << " - " << big_num_v1;
}

TEST_F(Subtraction, negative_ans) {
	IBusko::LongNumber ans = IBusko::LongNumber("-6656666666666666666666");
	IBusko::LongNumber res;
	res = big_num_v1 - big_num_v2;
	ASSERT_EQ(res, ans);
		<< "Неправильно посчитано: " << big_num_v1 << " - " << big_num_v2;
}
}
//Tests of "*"
//TODO

//Testf of "/"
//TODO

//Tests 0f "%"
//TODO

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
