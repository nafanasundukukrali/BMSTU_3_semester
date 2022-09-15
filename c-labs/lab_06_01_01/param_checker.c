#include "param_checker.h"

short check_field_command(char *input_field)
{
    return ((strlen(input_field) == NAME_FIELD_LEN &&
            (!strncmp(input_field, NAME_FIELD, NAME_FIELD_LEN) || 
            !strncmp(input_field, YEAR_FIELD, YEAR_FIELD_LEN))) ||
            (strlen(input_field) == MAX_FIELD_LEN &&
             !strncmp(input_field, TITLE_FIELD, TITLE_FIELD_LEN)));
}

void copy_with_start_position(char goal_word[MAX_NAME_LEN + 1], size_t start_position, char *copy_word, size_t copy_count)
{
    size_t  count  = 0;

    while (start_position < MAX_NAME_LEN && count < copy_count)
    {
        goal_word[start_position] = copy_word[count];
        start_position++;
        count++;
    }
}

short get_search_value(char *arg, char *search_value)
{
    //if (argc > PARAMS_MIN_COUNT + 1 && argv[PARAMS_MIN_COUNT][0] != '"')
    //    return FALSE;

    if (strlen(arg) > MAX_NAME_LEN)
        return FALSE;

    strncpy(search_value, arg, MAX_NAME_LEN);

    //int param_counter = PARAMS_MIN_COUNT;
    //size_t position_in_value = 0;

    //while (param_counter < argc)
    //{
    //    size_t value_size = strlen(argv[param_counter]);

    //    if (param_counter + 1 == argc && argv[param_counter][value_size - 1] == '"')
    //        value_size--;
    //    else if (param_counter + 1 == argc && argc > PARAMS_MIN_COUNT + 1)
    //        return FALSE;

    //    if (value_size + position_in_value > MAX_NAME_LEN)
    //        return FALSE;
        
    //copy_with_start_position(search_value, position_in_value, argv[param_counter], value_size);
    //position_in_value += value_size;
    //param_counter++;
    //}

    //search_value[position_in_value] = '\0';

    return TRUE;
}
