#include "file_io.h"

short read_line(FILE *file, char *string, size_t length)
{
    short return_code = 0;

    if (!fgets(string, length + 2, file))
    {
        return_code = ERROR_GET_DATA;
    }
    else
    {
        size_t actual_length = strlen(string);

        if (string[actual_length - 1] != '\n')
            return_code = ERROR_GET_DATA;
        else
            string[actual_length - 1] = '\0';
    }

    return return_code;
}

short read_data_from_file(film_t films[MAX_FILMS_ARRAY_LEN], FILE *file, char *field, size_t *real_array_size)
{
    size_t i = 0;
    film_t buffer_film;
    char buffer[MAX_NAME_LEN + 2];

    rewind(file);

    while (read_line(file, buffer_film.title, MAX_NAME_LEN) == EXIT_SUCCESS)
    {
        if (read_line(file, buffer_film.name, MAX_NAME_LEN) != EXIT_SUCCESS)
            return ERROR_GET_DATA;

        if (read_line(file, buffer, MAX_NAME_LEN) != EXIT_SUCCESS)
            return ERROR_GET_DATA;

        if (sscanf(buffer, "%u", &buffer_film.year) != READ_STRING_COUNT)
            return ERROR_GET_DATA;

        put_data_to_films_array(films, field, &buffer_film, i);

        i++;
    }
    
    if (!feof(file))
        return ERROR_INPUT_LINES_VALUE;

    *real_array_size = i;

    return EXIT_SUCCESS;
}

void print_all_films(film_t films[MAX_FILMS_ARRAY_LEN], size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%s\n", films[i].title);
        printf("%s\n", films[i].name);
        printf("%u\n", films[i].year);
    }
}

void print_one_film(film_t *film)
{
    printf("%s\n", film->title);
    printf("%s\n", film->name);
    printf("%u\n", film->year);
}

short find_value_in_list(file_t films_file, char *field, char search_value[MAX_NAME_LEN + 1], short search_value_init_status)
{
    film_t films[MAX_FILMS_ARRAY_LEN];
    memset(&films, 0, sizeof(film_t) * MAX_FILMS_ARRAY_LEN);

    size_t real_array_size = 0;

    if (films_file.file_size % ONE_FILM_FIELDS_COUNT != 0 ||
             films_file.file_size / ONE_FILM_FIELDS_COUNT > MAX_FILMS_ARRAY_LEN)
    {
        fclose(films_file.opened_file);
        return ERROR_FILES_STRING_COUNT;
    }

    short return_code = read_data_from_file(films, films_file.opened_file, field, &real_array_size);

    if (return_code)
    {
        fclose(films_file.opened_file);
        return return_code;
    }

    if (!search_value_init_status)
    {
        print_all_films(films, real_array_size);
    }
    else
    {
        film_t buffer_film;
        
        if (strncmp("year", field, NAME_FIELD_LEN))
        {
            return_code = binnary_search(films, real_array_size, field, search_value, 0, &buffer_film);
        }
        else {
            unsigned year;

            if (sscanf(search_value, "%u", &year) != READ_STRING_COUNT)
            {
                fclose(films_file.opened_file);
                return ERROR_GET_DATA;
            }

            return_code = binnary_search(films, real_array_size, field, search_value, year, &buffer_film);
        }
        
        if (return_code)
            printf("%s\n", "Not found");
        else
            print_one_film(&buffer_film);
    }

    return EXIT_SUCCESS;
}

size_t get_file_size(FILE *file)
{
    if (feof(file))
        rewind(file);

    size_t counter = 0;
    char buffer[MAX_NAME_LEN + 2];
    memset(buffer, 0, MAX_NAME_LEN + 2);

    while (file && !feof(file) && read_line(file, buffer, MAX_NAME_LEN) == EXIT_SUCCESS)
        counter++;
    // if (!feof(file) || !file)
    //    return 0;

    return counter;
}

file_t open_and_check_file(const char *file_name)
{
    FILE *file_input = fopen(file_name, "r");
    
    file_t result_file_information;

    size_t file_size = 0;

    if (file_input)
        file_size = get_file_size(file_input);

    if (!file_input || !file_size)
    {
        if (file_input)
            fclose(file_input);

        result_file_information.opened_file = NULL;
        result_file_information.file_size = 0;

        return result_file_information;
    }

    result_file_information.opened_file = file_input;
    result_file_information.file_size = file_size;

    return result_file_information;
}
