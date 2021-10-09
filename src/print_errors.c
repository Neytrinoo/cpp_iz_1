#include <stdio.h>

#include "print_errors.h"
#include "result_codes.h"

void print_errors(FILE *output, int error_code) {
    if (output == NULL) {
        return;
    }

    switch (error_code) {
        case NULL_POINTER_EXCEPTION:
            fprintf(output, "%s", "Null pointer passed");
            break;
        case INVALID_FORMAT:
            fprintf(output, "%s", "Invalid format");
            break;
        case INVALID_NUM:
            fprintf(output, "%s", "Invalid num");
            break;
    }
}
