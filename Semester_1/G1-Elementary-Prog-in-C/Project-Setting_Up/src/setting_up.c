/*
** EPITECH PROJECT, 2024
** Project-Setting_Up
** File description:
** setting_up
*/
#include "../include/my.h"
#include "../include/call.h"
#include "../include/struct.h"

int setting_up(char *filepath, map_t *map)
{
    int biggest_square = 0;

    map->array = my_str_to_word_array(load_2d_arr_from_file
        (filepath, map->nb_rows, map->nb_cols));
    map->nb_cols = fs_get_number_from_first_line(filepath);
    map->nb_rows = my_strlen(map->array[0]);
    for (int i = 0; i < map->nb_rows; i++) {
        map->row = i;
        for (int j = 0; j < map->nb_cols; j++) {
            map->col = j;
            biggest_square = find_biggest_square(map);
        }
    }
    replace_char(map, biggest_square);
    return 0;
}

void replace_char(map_t *map, int biggest_square)
{
    for (int i = map->row; i < map->row + biggest_square; i++) {
        for (int j = map->col; j < map->col + biggest_square; j++) {
            map->array[i][j] = 'x';
        }
    }
    print_2d_arr(map->array, map->nb_rows, map->nb_cols);
}

int print_2d_arr(char **arr, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            my_putchar(arr[i][j]);
        }
        mini_printf("nb_rows : %d\n", nb_rows);
        my_putchar('\n');
    }
    return 0;
}
