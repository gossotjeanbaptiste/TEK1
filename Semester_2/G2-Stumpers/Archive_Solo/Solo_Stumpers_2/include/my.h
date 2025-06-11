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
char *case_sensitive(char *str);
int anagram(char *str1, char *str2);
int verifier(int i, char *str1_c, char *str2_c);
#endif /* MY_H */
