/*
** EPITECH PROJECT, 2018
** header file
** File description:
** header file
*/

#ifndef HEAD
#define HEAD

#include "include/lib_headerfile.h"
#include "lib/my_printf/headerfile_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct
{
    int x;
    int y;
} coordinates;

typedef struct
{
    coordinates *pos;
    int size;
} biggest_square;

char **split_str(char *str, char split);
char *open_file(char *path);
int is_square_of_size(char **map, coordinates *top_left, int size);
void set_coordinates(coordinates *coords, int x, int y);
int pos_find_biggest_square(char **map, coordinates *top_left,
                            coordinates *field, biggest_square *square);
int mark_square(char **map, biggest_square *square);

#endif
