/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** my
*/
#include <stdarg.h>

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void handle_string(const char *format, va_list args);
void handle_integer(const char *format, va_list args);
void handle_char(va_list args);
void handle_default(char c);
void verification_switch(const char *format, va_list args, int i);
void mini_vprintf(const char *format, va_list args);
int mini_printf(const char *format, ...);
int error_handler(const char *format, ...);
int count_format_specifiers(const char *format);
int count_arguments(va_list args, const char *format);
#endif
