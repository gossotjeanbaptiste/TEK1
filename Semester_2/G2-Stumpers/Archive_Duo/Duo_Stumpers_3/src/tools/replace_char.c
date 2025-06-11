/*
** EPITECH PROJECT, 2025
** tools
** File description:
** replace_char
*/

void replace_char(const char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '0')
            str[i] = c;
}
