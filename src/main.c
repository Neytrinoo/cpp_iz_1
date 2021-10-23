#include <stdio.h>
#include <malloc.h>

#include "io_functions.h"
#include "into_roman_nums.h"
#include "result_codes.h"
#include "print_errors.h"

/*Вариант #48
Составить программу для перевода исходного целого в корректно сформированную строку с записью этого числа римскими цифрами
— символами {I, V, X, L, C, D, M}. Результат (запись) вернуть из функции как возвращаемое значение, а длину записи — как
 выходное значение параметра-указателя. */


int main() {
    int num, length;
    printf("Enter a number from 1 to 3999:");
    int result_code = input_num(stdin, &num);
    if (result_code == SUCCESS) {
        char *result = into_roman_nums(num, &length);
        if (result != NULL) {
            output_roman_num(stdout, result);
            free(result);
        } else {
            print_errors(stdout, INVALID_NUM);
        }
    } else {
        print_errors(stdout, result_code);
    }


    return result_code == SUCCESS ? 0 : result_code;
}
