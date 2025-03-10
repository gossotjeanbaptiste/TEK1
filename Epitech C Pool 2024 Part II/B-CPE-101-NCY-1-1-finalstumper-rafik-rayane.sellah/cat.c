/*
** EPITECH PROJECT, 2024
** day 12
** File description:
** cat
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int main(int ac, char *av[])
{
    int fd = 0;
    char buffer[256];
    int nb_read;

    for (int nbr = 1; nbr < ac; nbr++) {
        fd = open(av[nbr], O_RDONLY);
        lire(fd);
        close(fd);
    }
    return 0;
}

int lire(int fd)
{
    char buffer[256];
    int nb_read;

    nb_read = read(fd, buffer, 256);
    while (nb_read != 0) {
        write(1, buffer, nb_read);
        nb_read = read(fd, buffer, 256);
        return 0;
    }
}
