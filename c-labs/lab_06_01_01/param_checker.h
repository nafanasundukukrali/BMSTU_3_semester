#ifndef PARAM_CHECKER_H
#define PARAM_CHECKER_H

#include "film.h"
#include "string.h"
#include "stdio.h"

#define TRUE 1                                                                                                                                                                                             
#define FALSE 0    

#define PARAMS_MIN_COUNT 3

#define FIELD_IS_FULL_PARAM_COUNT 4

short check_field_command(char *input_field);

void copy_with_start_position(char goal_word[MAX_NAME_LEN + 1], size_t start_position, char *copy_word, size_t copy_count);

short get_search_value(char *arg, char *seacrh_value);

#endif
