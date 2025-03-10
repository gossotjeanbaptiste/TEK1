/*
** EPITECH PROJECT, 2024
** main
** File description:
** main file
*/

#include <unistd.h>
#include "rush3.h"
#include "include/my.h"

int main(char *buffer)
{
    int BUFF_SIZE = my_strlen(buffer);
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = read(0, buff + offset, BUFF_SIZE - offset);

    while (len > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
