/*
** EPITECH PROJECT, 2025
** Bootstrap-My_Sudo
** File description:
** check_password
*/
#include "../include/include.h"

int check_password(const char *password_hash)
{
    crypt(password_hash, "salt");
}