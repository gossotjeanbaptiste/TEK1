/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/my_sudo.h"

int main(int argc, char **argv)
{
    struct passwd *pw = NULL;
    char *user = NULL;
    char command[1024] = {0};

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [user]\n", argv[0]);
        return 84;
    } else if (argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("usage: ./my_sudo -h\n" \
            "usage: ./my_sudo [-ugEs] [command [args ...]]");
            return 0;
    }
    if (main_verif(argc, argv, &user, &pw) == 84)
        return 84;
    strcat(command, argv[1]);
    execute_command(command, user);
    return 0;
}

int main_verif(int argc, char **argv, char **user, struct passwd **pw)
{
    if (argc == 2) {
        *user = getenv("USER");
        if (*user == NULL) {
            fprintf(stderr, "Unable to determine the current user\n");
            return 84;
        }
        *pw = getpwuid(getuid());
        if (*pw == NULL) {
            perror("getpwuid");
            return 84;
        }
        *user = (*pw)->pw_name;
    } else {
        *user = argv[2];
    }
    return 0;
}
