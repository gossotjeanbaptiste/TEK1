/*
** EPITECH PROJECT, 2024
** convert_num_to_str
** File description:
** function that converts a num to a str
*/
int my_convert_num_to_str(int num, char *str)
{
    int i = 0;

    if (num == 0) {
        i++;
        str[i] = '\0';
        return i;
    }
    while (num != 0) {
        i++;
        str[i] = (num % 10) + '\0';
        num = num / 10;
    }
    return i;
}
