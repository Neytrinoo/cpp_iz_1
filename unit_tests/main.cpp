#include <gtest/gtest.h>

extern "C" {
#include "into_roman_nums.h"
#include "result_codes.h"
#include "io_functions.h"
#include "print_errors.h"
}


TEST(TestIntoRomanNums, test) {
    EXPECT_EQ(into_roman_nums(10, nullptr), nullptr);
    EXPECT_EQ(into_roman_nums(10, nullptr), nullptr);

    char *roman_nums[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int roman_arab_nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    char *res_str = NULL;
    int length;

    EXPECT_EQ(into_roman_nums(10, nullptr), nullptr);
    EXPECT_EQ(into_roman_nums(-1, &length), nullptr);
    EXPECT_EQ(into_roman_nums(0, &length), nullptr);
    EXPECT_EQ(into_roman_nums(4000, &length), nullptr);

    for (int i = 0; i < sizeof(roman_arab_nums) / sizeof(int); ++i) {
        res_str = into_roman_nums(roman_arab_nums[i], &length);
        EXPECT_STREQ(res_str, roman_nums[i]);
        EXPECT_EQ(length, i % 2 == 0 ? 1 : 2);
        free(res_str);
    }

    res_str = into_roman_nums(43, &length);
    EXPECT_STREQ(res_str, "XLIII");
    EXPECT_EQ(length, 5);
    free(res_str);

    res_str = into_roman_nums(3, &length);
    EXPECT_STREQ(res_str, "III");
    EXPECT_EQ(length, 3);
    free(res_str);

    res_str = into_roman_nums(39, &length);
    EXPECT_STREQ(res_str, "XXXIX");
    EXPECT_EQ(length, 5);
    free(res_str);

    res_str = into_roman_nums(89, &length);
    EXPECT_STREQ(res_str, "LXXXIX");
    EXPECT_EQ(length, 6);
    free(res_str);

    res_str = into_roman_nums(399, &length);
    EXPECT_STREQ(res_str, "CCCXCIX");
    EXPECT_EQ(length, 7);
    free(res_str);

    res_str = into_roman_nums(443, &length);
    EXPECT_STREQ(res_str, "CDXLIII");
    EXPECT_EQ(length, 7);
    free(res_str);

    res_str = into_roman_nums(899, &length);
    EXPECT_STREQ(res_str, "DCCCXCIX");
    EXPECT_EQ(length, 8);
    free(res_str);

    res_str = into_roman_nums(905, &length);
    EXPECT_STREQ(res_str, "CMV");
    EXPECT_EQ(length, 3);
    free(res_str);

    res_str = into_roman_nums(3999, &length);
    EXPECT_STREQ(res_str, "MMMCMXCIX");
    EXPECT_EQ(length, 9);
    free(res_str);
}

TEST(TestIOFunctions, test) {
    // input_num()
    int num;

    EXPECT_EQ(input_num(stdin, nullptr), NULL_POINTER_EXCEPTION);
    EXPECT_EQ(input_num(nullptr, &num), NULL_POINTER_EXCEPTION);

    FILE *f = fopen("../unit_tests/test1_pos.in", "r");
    EXPECT_EQ(input_num(f, &num), SUCCESS);
    EXPECT_EQ(num, 312);
    fclose(f);

    f = fopen("../unit_tests/test1_neg.in", "r");
    EXPECT_EQ(input_num(f, &num), INVALID_FORMAT);
    fclose(f);


    // output_roman_num()
    char *roman_num = "XIV";
    EXPECT_EQ(output_roman_num(nullptr, roman_num), NULL_POINTER_EXCEPTION);
    EXPECT_EQ(output_roman_num(stdout, nullptr), NULL_POINTER_EXCEPTION);

    num = 1239;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}