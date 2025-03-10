/*
** EPITECH PROJECT, 2025
** Project-my_sudo
** File description:
** recode
*/
#include "include/my.h"
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char *get_user_group(uid_t uid)
{
    int file = open("/etc/passwd", O_RDONLY);
    int i = 1;
    int len;
    char **word_array;
    char *line;

    if (file != 0)
        return NULL;
    word_array = my_str_to_word_array(open);
    len = word_array[0];
    line = getline(word_array, len, line);
    while (line != NULL) {
        len = word_array[i];
        line = strtok(line, ":");
        if (atoi(line) == uid) {
            return line;
        }
        line = getline(word_array, len, line);
        i++;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2) 
        return 84;
    if (get_user_group(atoi(argv[1])) == NULL) {
        return 84;
    }
    return 0;
}