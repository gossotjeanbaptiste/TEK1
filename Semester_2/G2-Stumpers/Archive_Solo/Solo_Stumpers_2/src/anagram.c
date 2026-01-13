/*
** EPITECH PROJECT, 2025
** solo stumper 2
** File description:
** anagram
*/

#include "../include/my.h"

int anagram(char *str1, char *str2)
{
    char *str1_c = case_sensitive(str1);
    char *str2_c = case_sensitive(str2);
    int len_s1 = my_strlen(str1_c);
    int len_s2 = my_strlen(str2_c);

    if (len_s1 != len_s2) {
        my_putstr("no anagrams.\n");
        return 84;
    }
    for (int i = 0; i != len_s1; i++) {
        if (verifier(i, str1_c, str2_c) == 84) {
            return 84;
        }
    }
    my_putstr("anagram!\n");
    return 0;
}

int verifier(int i, char *str1_c, char *str2_c)
{
    int len_s2 = my_strlen(str2_c);

    for (int j = 0; j != len_s2 - 1; j++) {
        if (str1_c[i] != str2_c[j] && str2_c[j + 1] == '\0') {
            my_putstr("no anagrams.\n");
            return 84;
        }
    }
    return 0;
}
