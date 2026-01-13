/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** declaration of all functions
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>


#ifndef SUDO_H
    #define SUDO_H

typedef struct passwd_s {
    char *pw_name;
    char *pw_passwd;
    uid_t pw_uid;
    gid_t pw_gid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
} passwd_t;

typedef struct var_s {
    uid_t euid;
    FILE *passwd_file;
    char line[256];
    char *token;
    char *username;
    uid_t uid;
    int ret_flag;
    int ret_val;
} var_t;

int main(int argc, char **argv);
void my_sudo(int argc, char **argv);


int error_file(FILE *file);
int error_dir(DIR *dir);
int error_handling(FILE *file, DIR *dir);
int execute_command(char *command, char *user);

int verifier(passwd_t *pw, char *user, int *retFlag);
int main_verif(int argc, char **argv, char **user, struct passwd **pw);
int initialize_var(var_t *var);
int execute_command(char *command, char *user);
int parse_passwd_line(char *line, passwd_t *pw);
passwd_t *get_user_passwd(var_t *var);
passwd_t *find_user_passwd(var_t *var);

#endif /* !SUDO_H */
