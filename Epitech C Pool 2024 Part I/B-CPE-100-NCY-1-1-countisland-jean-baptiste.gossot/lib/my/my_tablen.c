/*
** EPITECH PROJECT, 2024
** my_tablen
** File description:
** return the len of a tab
*/

int my_tablen(char *const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        i++;
    }
    return i;
}
