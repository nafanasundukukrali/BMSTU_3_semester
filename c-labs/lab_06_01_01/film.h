#ifndef FILM_H
#define FILM_H

#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define NAME_FIELD_LEN 4
#define TITLE_FIELD_LEN 5
#define YEAR_FIELD_LEN 4

#define NAME_FIELD "name"
#define TITLE_FIELD "title"
#define YEAR_FIELD "year"

#define MAX_FILMS_ARRAY_LEN 15
#define ONE_FILM_FIELDS_COUNT 3

#define MAX_NAME_LEN 25UL
#define MAX_FIELD_LEN 5

#define ERROR_FIND_FILM 21

typedef struct
{
    char title[MAX_NAME_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    unsigned year;
} film_t;

void put_data_to_films_array(film_t films[MAX_FILMS_ARRAY_LEN], char *field, film_t *buffer_film, size_t actual_array_size);

short binnary_search(film_t films[MAX_FILMS_ARRAY_LEN], size_t array_length, char *field, char *string_value, unsigned number_value, film_t *buffer_film);

#endif
