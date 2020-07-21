/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header_file.h"

void free_arr(char **arr, coordinates *field)
{
    int line = 0;

    arr--;
    while (arr[line] != NULL) {
        free(arr[line]);
        line++;
    }
    free(field);
    free(arr);
}

void set_coordinates(coordinates *coords, int x, int y)
{
    coords->x = x;
    coords->y = y;
}

void free_stuff(coordinates *top_left, biggest_square *square)
{
    free(top_left);
    free(square->pos);
    free(square);
}

int find_biggest_square(char **map, coordinates *field)
{
    coordinates *top_left = malloc(sizeof(coordinates));
    biggest_square *square = malloc(sizeof(biggest_square));

    set_coordinates(top_left, 0, 0);
    square->pos = malloc(sizeof(coordinates));
    set_coordinates(square->pos, 0, 0);
    square->size = 0;
    while (top_left->x + square->size <= field->x &&
            top_left->y + square->size <= field->y) {
        pos_find_biggest_square(map, top_left, field, square);
        if (top_left->x + square->size == field->x  &&
            top_left->y + square->size < field->y) {
            top_left->x = 0;
            top_left->y = top_left->y + 1;
        } else {
            top_left->x = top_left->x + 1;
        }
    }
    mark_square(map, square);
    free_stuff(top_left, square);
}

int main(int ac, char **av)
{
    char *input_str;
    char **map;
    coordinates *field = malloc(sizeof(coordinates));

    if (ac != 2)
        exit(84);
    input_str = open_file(av[1]);
    map = split_str(input_str, '\n');
    set_coordinates(field, (my_strlen(map[1]) - 1), my_getnbr(input_str));
    map++;
    free(input_str);
    find_biggest_square(map, field);
    free_arr(map, field);
}
