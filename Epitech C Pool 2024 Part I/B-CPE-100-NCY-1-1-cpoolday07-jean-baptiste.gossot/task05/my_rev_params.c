/*
** EPITECH PROJECT, 2024
** my_rev_params
** File description:
** print all params but in reverse order
*/

void my_rev_params(int count, char *args[])
{
    int len;

    for (int i = count - 1; i != -1; i--) {
        len = my_strlen(args[i]);
        write(1, args[i], len);
        write(1, "\n", 1);
    }
}
