/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** main
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

int my_hunter(struct csfml_var *csfml_var)
{
    if (!csfml_var->window || !csfml_var->texture_sprite || !csfml_var->sprite
    || !csfml_var->texture_background)
        return EXIT_FAILURE;
    else
        start_game(csfml_var);
    return EXIT_SUCCESS;
}
