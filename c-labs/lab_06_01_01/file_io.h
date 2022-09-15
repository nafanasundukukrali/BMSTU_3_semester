#ifndef FILE_IO_H
#define FILE_IO_H

#include "film.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define ERROR_GET_DATA 11
#define ERROR_FILES_STRING_COUNT 12
#define ERROR_INPUT_LINES_VALUE 13

#define READ_STRING_COUNT 1

typedef struct
{
    FILE *opened_file;
    size_t file_size;
} file_t;

file_t open_and_check_file(const char *file_name);
short find_value_in_list(file_t films_file, char *field, char search_value[MAX_NAME_LEN + 1], short search_value_init_status);

#endif
