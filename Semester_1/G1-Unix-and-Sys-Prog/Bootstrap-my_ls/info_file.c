/*
** EPITECH PROJECT, 2024
** Bootstrap-my_ls
** File description:
** info_file
*/

#include "include/my.h"
#include "include/test.h"

char type_file(mode_t mode)
{
    if (S_ISREG(mode)) {
        return '-';
    }
    if (S_ISDIR(mode)) {
        return 'd';
    }
    if (S_ISCHR(mode)) {
        return 'c';
    }
    if (S_ISBLK(mode)) {
        return 'b';
    }
    if (S_ISFIFO(mode)) {
        return 'p';
    }
    if (S_ISLNK(mode)) {
        return 'l';
    }
    if (S_ISSOCK(mode))
        return 's';
}

int info_file(char *file_name)
{
    struct stat sb;
    struct passwd *pwd;
    struct group *grp;
    char *time;

    if (stat(file_name, &sb) == -1) {
        perror("stat");
        return 84;
    }
    pwd = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);
    if (pwd == NULL || grp == NULL) {
        perror("getpwuid/getgrgid");
        return 84;
    }
    mini_printf("Name: %s \nType: %c \nInode: %d \nHard Link: %d \nSize: %d"
    "\nAllocated space: %d \nMinor: %d"
    "\nMajor: %d\nUID: %d\nGID: %d\n", file_name, type_file(sb.st_mode),
    sb.st_ino, sb.st_nlink, sb.st_size, sb.st_blocks, minor(sb.st_dev),
    major(sb.st_dev), sb.st_uid, sb.st_gid);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        info_file(".");
    } else {
        for (int i = 1; i < ac; i++) {
            info_file(av[i]);
        }
    }
    return 0;
}
