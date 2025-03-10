/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** concatenante n char in src string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char dest_cat[len_dest];
    char src_cat[len_src];

    my_strncmp(dest_cat, dest, nb);
    my_strncmp(src_cat, src, nb);
    return my_strcat(dest_cat, src_cat);
}
