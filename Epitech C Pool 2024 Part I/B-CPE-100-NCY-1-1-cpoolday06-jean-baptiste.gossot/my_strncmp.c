/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** compare two strings but only for n bytes
*/

int my_strncmp(const char s1, const char s2, int n)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    char s1_cp[len_s1];
    char s2_cp[len_s2];

    my_strncpy(s1_cp, s1, n);
    my_strncpy(s2_cp, s2, n);
    return my_strcmp(s1_cp, s2_cp);
}
