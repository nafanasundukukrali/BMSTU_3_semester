#include "file_io.h"
#include "param_checker.h"

#define ERROR_INPUT_PARAMS 1

int main(int argc, char **argv)
{
    if (argc < PARAMS_MIN_COUNT || argc > PARAMS_MIN_COUNT + 1)
    {
        return ERROR_INPUT_PARAMS;
    }
    else
    {
        file_t films_file = open_and_check_file(argv[1]);
        
        char search_value[MAX_NAME_LEN + 1];

        if (!films_file.opened_file || 
            !check_field_command(argv[2]) || 
            (argc > PARAMS_MIN_COUNT && !get_search_value(argv[3], search_value)))
        {
            if (films_file.opened_file)
                fclose(films_file.opened_file);

            return ERROR_INPUT_PARAMS;
        }

        return find_value_in_list(films_file, argv[2], search_value, argc >= FIELD_IS_FULL_PARAM_COUNT);    
    }

    return EXIT_SUCCESS;
}
