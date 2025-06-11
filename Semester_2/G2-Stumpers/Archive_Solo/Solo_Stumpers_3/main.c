/*
** EPITECH PROJECT, 2025
** solo stumper 3
** File description:
** main
*/
#include "include/my.h"

int main(int argc, char **argv)
{
    char *er = "Error: the second parameter must be greater than the first.\n";
    int len_err = my_strlen(er);

    if (argc != 3) {
        return 84;
    } else if (atoi(argv[1]) > atoi(argv[2])) {
        write(2, er, len_err);
        return 84;
    } else {
        fizzbuzz(atoi(argv[1]), atoi(argv[2]));
    }
    return 0;
}
