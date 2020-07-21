/*
** EPITECH PROJECT, 2018
** find biggest square
** File description:
** find biggest square
*/

#include "header_file.h"

int is_square_of_size(char **map, coordinates *top_left, int size)
{
    coordinates *pos = malloc(sizeof(coordinates));

    size--;
    set_coordinates(pos, top_left->x, top_left->y);
    while (pos->x <= top_left->x + size && pos->y <= top_left->y + size) {
        if (map[pos->y][pos->x] == 'o') {
            return (0);
        } else if (pos->y == top_left->y + size &&
                    pos->x < top_left->x + size) {
            pos->y = top_left->y;
            pos->x++;
        } else {
            pos->y++;
        }
    }
    free(pos);
    return (1);
}

int pos_find_biggest_square(char **map, coordinates *top_left,
                            coordinates *field, biggest_square *square)
{
    int size = square->size;
    int control = 1;

    while (control == 1 && (top_left->x + size) < field->x &&
            (top_left->y + size) < field->y) {
        size++;
        control = is_square_of_size(map, top_left, size);
        if (control == 1) {
            square->size = size;
            set_coordinates(square->pos, top_left->x, top_left->y);
        }
    }
}

void print_map(char **map)
{
    int y = 0;

    while (map[y] != NULL) {
        my_printf("%s", map[y]);
        y++;
    }
}

int mark_square(char **map, biggest_square *square)
{
    int x = square->pos->x;
    int y = square->pos->y;

    square->size--;
    while (x <= (square->pos->x + square->size) &&
            y <= (square->pos->y + square->size)) {
        map[y][x] = 'x';
        if (x == square->pos->x + square->size &&
            y < square->pos->y + square->size) {
            x = square->pos->x;
            y++;
        } else {
            x++;
        }
    }
    print_map(map);
}
