/*
** EPITECH PROJECT, 2024
** function_for_count_island
** File description:
**
*/

#ifndef FUNCTION_H
    #define FUNCTION_H
int get_x(char **world);
int get_y(char **world);
int position_checker(char **world, int x, int y, int count);
void del_around(char **world, int x, int y, int count);
int annexe_count_island(char **world, int x, int y);
int count_island(char **world);
#endif
