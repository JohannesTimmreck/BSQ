/*
** EPITECH PROJECT, 2018
** open file
** File description:
** open file and return content as char string
*/

#include "header_file.h"

char *open_file(char *path)
{
    int fd = 1;
    int check = 0;
    struct stat fileStat;
    char *input;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(84);
    if (stat(path, &fileStat) == -1)
        exit(84);
    input = malloc(sizeof(char) * (fileStat.st_size + 1));
    if (input == NULL)
        exit(84);
    input[fileStat.st_size] = '\0';
    check = read(fd, input, (fileStat).st_size);
    if (check == -1 || check == 0)
        exit(84);
    return (input);
}

char *fill_strings(char *input, char *output, int *counter, char split)
{
    int local_counter = *counter;
    int save = 0;

    while (input[local_counter] != split && input[local_counter] != '\0') {
        local_counter++;
    }
    save = local_counter + 1;
    output = malloc(sizeof(char) * (local_counter + 2));
    if (output == NULL)
        exit(84);
    local_counter = 0;
    while (*counter < save) {
        output[local_counter] = input[*counter];
        *counter = *counter + 1;
        local_counter++;
    }
    output[local_counter] = '\0';
    *counter++;
    return (output);
}

int count_split(char *str, char split)
{
    int size_of_arr = 0;
    int counter = 0;
    int count = 0;

    while (str[counter] != '\0') {
        if (str[counter] == split)
            size_of_arr++;
        counter++;
    }
    if (size_of_arr == 0)
        exit(84);
    return (size_of_arr);
}

char **split_str(char *str, char split)
{
    char **arr;
    int size_of_arr = count_split(str, split);
    int counter = 0;
    int count = 0;

    arr = malloc(sizeof(char *) * (size_of_arr + 2));
    if (arr == NULL)
        exit(84);
    arr[size_of_arr + 1] = NULL;
    while (count <= size_of_arr) {
        arr[count] = fill_strings(str, arr[count], &counter, split);
        count++;
    }
    return (arr);
}
