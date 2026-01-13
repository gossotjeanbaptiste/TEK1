/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** my_sudo
*/

#include "../include/my_sudo.h"
#include "../include/my.h"

int execute_command(char *command, char *user)
{
    passwd_t *pw;
    var_t *var = malloc(sizeof(var_t));

    if (var == NULL) {
        perror("malloc");
        return 84;
    }
    if (initialize_var(var) != 0) {
        return 84;
    }
    pw = get_user_passwd(var);
    if (pw == NULL) {
        return 84;
    }
    var->ret_val = verifier(pw, user, &var->ret_flag);
    if (var->ret_flag == 84)
        return var->ret_val;
    system(command);
    return 0;
}

passwd_t *get_user_passwd(var_t *var)
{
    passwd_t *pw = NULL;

    pw = find_user_passwd(var);
    fclose(var->passwd_file);
    return pw;
}

passwd_t *find_user_passwd(var_t *var)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    passwd_t *pw = malloc(sizeof(passwd_t));

    if (pw == NULL) {
        perror("malloc");
        return NULL;
    }
    read = getline(&line, &len, var->passwd_file);
    while (read != -1) {
        if (parse_passwd_line(line, pw) == 0) {
            free(line);
            return pw;
        }
        read = getline(&line, &len, var->passwd_file);
    }
    free(line);
    free(pw);
    return NULL;
}

int parse_passwd_line(char *line, passwd_t *pw)
{
    char *token;
    int field = 0;

    token = strtok(line, ":");
    while (token != NULL) {
        switch (field) {
            case 0:
                pw->pw_name = strdup(token);
                break;
            case 2:
                pw->pw_uid = atoi(token);
                break;
            default:
                break;
        }
        token = strtok(NULL, ":");
        field++;
    }
    return (field >= 3) ? 0 : -1;
}

int verifier(passwd_t *pw, char *user, int *retFlag)
{
    *retFlag = 1;
    if (pw == NULL) {
        return 84;
    }
    if (user == NULL) {
        return 84;
    }
    if (strcmp(pw->pw_name, user) != 0) {
        return 84;
    }
    if (pw == NULL) {
        fprintf(stderr, "User %s not found\n", user);
        return 84;
    }
    if (setuid(pw->pw_uid) != 0) {
        return 84;
    }
    return 0;
}
