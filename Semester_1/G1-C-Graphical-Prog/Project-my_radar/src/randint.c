/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** randint
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"
#include "../include/csfml_include.h"

int randint(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
