/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** how_many_user
*/

#include "../include/my.h"
#include "../include/call.h"

int open_utmp_file(void)
{
    int utmpfd = open(_PATH_UTMP, O_RDONLY);

    if (utmpfd == -1) {
        perror("open");
        return -1;
    }
    return utmpfd;
}

int count_users(int utmpfd)
{
    struct utmp current_record;
    int user_count = 0;
    unsigned long scurr_rec = sizeof(current_record);
    ssize_t readed;

    readed = read(utmpfd, &current_record, scurr_rec);
    while (readed == (ssize_t)scurr_rec) {
        if (current_record.ut_type == USER_PROCESS) {
            user_count++;
        }
        readed = read(utmpfd, &current_record, scurr_rec);
    }
    return user_count;
}

int print_user_count(int user_count)
{
    if (user_count <= 1)
        return printw(" %d user, ", user_count);
    else
        return printw(" %d users, ", user_count);
}

int how_many_user(void)
{
    int utmpfd = open_utmp_file();
    int user_count;

    if (utmpfd == -1)
        return 84;
    user_count = count_users(utmpfd);
    close(utmpfd);
    print_user_count(user_count);
    return 0;
}
