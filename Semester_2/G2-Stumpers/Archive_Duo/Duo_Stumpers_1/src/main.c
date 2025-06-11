/*
** EPITECH PROJECT, 2025
** main file stumper
** File description:
** main source file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/tools.h"

typedef struct {
    int bytes;
    int lines;
    int flag_q;
    int flag_v;
    char *filepath;
}options_t;

int my_atoi(const char *str) {
    return 0;
}

int run_without_path(void)
{
    return 0;
}

static int any_flag(options_t *op)
{
    return (op->bytes || op->lines != 10 || op->flag_q || op->flag_v);
}

static int check_and_process_c_flag(char **av, options_t *op, int index)
{
    if (!av[index + 1])
        return -1;
    op->bytes = my_atoi(av[index + 1]);
    op->lines = 10;
    return 0;
}

static int check_and_process_n_flag(char const * const*av, options_t *op, int index)
{
    if (!av[index + 1])
        return -1;
    op->lines = my_atoi(av[index + 1]);
    op->bytes = 0;
    return 0;
}

static int parse_options_qv(char *option, options_t *op)
{
    for (int i = 1; option[i]; i++) {
        if (option[i] == 'v') {
            op->flag_v = 1;
            op->flag_q = 0;
        }
        if (option[i] == 'q') {
            op->flag_q = 1;
            op->flag_v = 1;
        }
    }
}
static int parse_options_cn(char **av, options_t *op)
{
    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-')
            op->filepath = av[i];
        if (av[i][0] == '-' && (av[i][1] == 'v' || av[i][1] == 'q'))
            parse_options_qv(av[i], op);
        if (!my_strcmp(av[i], "-c") || !my_strcmp(av[i], "--bytes"))
            check_and_process_c_flag(av, op, i);            
        if (!my_strcmp(av[i], "-n") || !my_strcmp(av[i], "--lines"))
            check_and_process_n_flag(av, op, i);
        if (!my_strcmp(av[i], "-q") || !my_strcmp(av[i], "--quiet")
            || !my_strcmp(av[i], "--silent")) {
            op->flag_q = 1;
            op->flag_v = 0;
        }
        if (!my_strcmp(av[i], "-v") || !my_strcmp(av[i], "--verbose")) {
            op->flag_v = 1;
            op->flag_q = 0;
        }
    }
    return any_flag(op);
}


static void count_line(const char c, int *count)
{
    if (c == '\n')
        (*count)++;
    return;
}

int run_with_path(options_t *op)
{
    ssize_t len = 0;
    int fd = 0;
    char *buffer = 0;
    int count = 0;

    fd = open(op->filepath, O_RDONLY);
    len = read(fd, buffer, 1);
    while(count != op->lines && len) {
        write(1, buffer, len);
        len = read(fd, buffer, 1);
        count_line(buffer[len -1], &count);
    }
    
}

static int parse_path(options_t *op)
{
    if (op->filepath)
    {
        run_with_path(op);
    } else {
        run_without_path();
    }
}

int main(int ac, char **av)
{
    options_t op = {0, 10, 0, 0};

    parse_options_cn(av, &op);
    parse_path(&op);
    return 0;
}
