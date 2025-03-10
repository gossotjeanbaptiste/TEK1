/*
** EPITECH PROJECT, 2024
** my_print_params
** File description:
** display the arg which are give to the functions
*/

void my_print_params(int *count, char *args[])
{
    int len;

    for (int i = 0; i < count; i++) {
        len = my_strlen(args[i]);
        write(1, args[i], len);
        write(1, "\n", 1);
    }
}
