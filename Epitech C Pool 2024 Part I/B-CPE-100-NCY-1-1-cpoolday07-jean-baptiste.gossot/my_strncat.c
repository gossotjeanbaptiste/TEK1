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
    int j = 0;

    for (int i = 0; i < len_src && i < nb; i++) {
        dest[len_dest + i] = src[i];
        j++;
    }
    dest[len_dest + j] = '\0';
    return dest;
}
