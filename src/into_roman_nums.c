#include <string.h>
#include <malloc.h>

#include "into_roman_nums.h"

#define MAX_ROMAN_NUM_LENGTH 20

char *into_roman_nums(int num, int *length) {
    if (num <= 0 || num > 3999 || length == NULL) {
        return NULL;
    }

    static char *roman_nums[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    static int roman_arab_nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    char for_num[MAX_ROMAN_NUM_LENGTH];

    int for_num_ind = 0;

    for (size_t i = sizeof(roman_arab_nums) / sizeof(int) - 1; num > 0 && for_num_ind < MAX_ROMAN_NUM_LENGTH - 2; --i) {
        while (num / roman_arab_nums[i] > 0 && for_num_ind < MAX_ROMAN_NUM_LENGTH - 2) {
            strcpy(for_num + for_num_ind, roman_nums[i]);
            for_num_ind += strlen(roman_nums[i]);
            num -= roman_arab_nums[i];
        }
    }


    for_num[for_num_ind] = '\0';

    char *result_str = calloc(for_num_ind + 1, sizeof(char));
    strcpy(result_str, for_num);
    *length = for_num_ind;

    return result_str;
}