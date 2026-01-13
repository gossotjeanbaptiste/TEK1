/*
** EPITECH PROJECT, 2025
** Solo Stumper 1
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
	#include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
int my_strlen(char *str);
int my_putstr(char *str);
void my_putchar(char c);
void print_family_name(char *str, int i);
void verif_family_name(char *str, int i);
void print_part_name(char *str, int i);
void french_name_formatter(char *str);
#endif /* MY_H */
