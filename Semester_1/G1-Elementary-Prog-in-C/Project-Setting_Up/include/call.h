/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** call
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

#ifndef INCLUDED_CALL_H
    #define INCLUDED_CALL_H
void fs_cat_500_bytes(char const *filepath);
void fs_cat_x_bytes(char const *filepath, int x);
int fs_open_file(char const *filepath);
void fs_understand_return_of_read(int fd, char *buffer, int size);
int fs_get_number_from_first_line(char const *filepath);
int array_2d_sum(int **arr, int nb_rows, int nb_cols);
int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number);
int annexe_array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number);
int array_1d_sum(const int *arr, int size);
void array_1d_print_ints(const int *arr, int size);
void array_1d_print_chars(const char *arr);
char *mem_alloc(char const *a, char const *b);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **mem_dup_2d_array(int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
char *load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
int find_biggest_square(map_t *map);
int annexe_un_find_biggest_square(map_t *map, int max_size, int size, int i);
int annexe_deux_find_biggest_square(map_t *map, int size, int i);
int print_2d_arr(char **arr, int nb_rows, int nb_cols);
void replace_char(map_t *map, int biggest_square);
int setting_up(char *filepath, map_t *map);
int main(int ac, char **av);
#endif /* !INCLUDED_CALL_H */
