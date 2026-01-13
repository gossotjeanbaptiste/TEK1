/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** display the content of an array of word
*/
#include "my.h"


void my_show_word_array(char *words[])
{
    int size = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < size; i++) {
        mini_printf("%s\n", words[i]);
    }
}
