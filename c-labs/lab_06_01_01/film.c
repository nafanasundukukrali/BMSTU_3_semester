#include "film.h"

short check_film_param(film_t *current_film, film_t *accuracy_film, char *field)
{
    if (strlen(field) == MAX_FIELD_LEN && !strncmp(field, TITLE_FIELD, MAX_FIELD_LEN))
        return strncmp(accuracy_film->title, current_film->title, MAX_NAME_LEN) > 0;
    else if (!strncmp(field, NAME_FIELD, NAME_FIELD_LEN))
        return strncmp(accuracy_film->name, current_film->name, MAX_NAME_LEN) > 0;
    
    return accuracy_film->year > current_film->year;
}

void put_data_to_films_array(film_t films[MAX_FILMS_ARRAY_LEN], char *field, film_t *buffer_film, size_t actual_array_size)
{
    size_t find_position = 0;

    while (actual_array_size != 0 && check_film_param(&films[find_position], buffer_film, field) && 
            find_position < actual_array_size && find_position < MAX_FILMS_ARRAY_LEN)
        find_position++;
     
    size_t i = find_position + 1;
    film_t new_buffer = films[find_position], new_buffer_buffer;

    while (i < actual_array_size + 1)
    {
        new_buffer_buffer = films[i];
        films[i] = new_buffer;
        new_buffer = new_buffer_buffer;
        i++;
    }
    
    films[find_position] = *buffer_film;
}

short check_film_value(film_t *current_film, char *accuracy_film_string, unsigned  accuracy_film_number, char *field)
{
    if (!strncmp(field, TITLE_FIELD, MAX_FIELD_LEN))
        return strncmp(accuracy_film_string, current_film->title, MAX_NAME_LEN);
    else if (!strncmp(field, NAME_FIELD, NAME_FIELD_LEN))
        return strncmp(accuracy_film_string, current_film->name, MAX_NAME_LEN);
    
    return accuracy_film_number - current_film->year;
}

short binnary_search(film_t films[MAX_FILMS_ARRAY_LEN], size_t array_length, char *field, char *string_value, unsigned number_value, film_t *buffer_film)
{
    size_t left = 0;
    size_t right = array_length;

    while (left < right - 1) {
        size_t medium = (left + right) / 2;

        if (check_film_value(&films[medium], string_value, number_value, field) >= 0)
            left = medium;
        else
            right = medium;
    }

    if (left < right && !check_film_value(&films[left], string_value, number_value, field))
    {
        *buffer_film = films[left];
        return EXIT_SUCCESS;
    }

    return ERROR_FIND_FILM;
}
