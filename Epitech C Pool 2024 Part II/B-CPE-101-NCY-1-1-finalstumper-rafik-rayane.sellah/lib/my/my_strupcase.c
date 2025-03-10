/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** put every letter of a string in uppercase
*/

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' || str[i] <= 'Z')
            str[i] = str[i];
        if (str[i] >= 'a' || str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
