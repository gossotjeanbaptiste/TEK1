/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** close_window
*/
#include "include/csfml_include.h"

void close_window(struct csfml_var *csfml_var)
{
    sfRenderWindow_close(csfml_var->window);
}
