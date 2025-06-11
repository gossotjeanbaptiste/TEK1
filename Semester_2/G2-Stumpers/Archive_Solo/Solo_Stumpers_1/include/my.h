/*
** EPITECH PROJECT, 2025
** Solo Stumper 1
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
int my_strlen(char *str);
int my_putstr(char *str);
void my_putchar(char c);
int *position(char *str);
void clean_str(char *str);
int count_space(char *str);
char *strncopy_index(char *str, int start_index, int end_index);
char *annexe_clean_str(int j, int i, int *position_array, char *str);
#endif /* MY_H */
