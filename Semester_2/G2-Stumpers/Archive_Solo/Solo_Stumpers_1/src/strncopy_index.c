/*
** EPITECH PROJECT, 2025
** clean string (solo stumper 1)
** File description:
** strncopy_index
*/

char *strncopy_index(char *str, int start_index, int end_index)
{
    char *new_str[end_index - start_index];
    int i = 0;
    int j = start_index;

    while (i != (end_index - start_index) && j != end_index) {
        new_str[i] = str[j];
        i++;
        j++;
    }
    return *new_str;
}
