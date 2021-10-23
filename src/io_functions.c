#include <stdio.h>

#include "io_functions.h"
#include "result_codes.h"

int input_num(FILE *file, int *num) {
    if (file == NULL || num == NULL) {
        return NULL_POINTER_EXCEPTION;
    }

    return (fscanf(file, "%d", num) == 1) ? SUCCESS : INVALID_FORMAT;
}

int output_roman_num(FILE *file, char *roman_num) {
    if (file == NULL || roman_num == NULL) {
        return NULL_POINTER_EXCEPTION;
    }
    fprintf(file, "%s", roman_num);

    return SUCCESS;
}
