/*
** EPITECH PROJECT, 2024
** Bootstrap-My_radar
** File description:
** start_game
*/
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"
#include "../include/csfml_include.h"

int start_game(struct csfml_var *csfml_var)
{
    if (!csfml_var->window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(csfml_var->window)) {
        analyse_events(csfml_var);
        sfRenderWindow_clear(csfml_var->window, sfBlack);
        draw_circles(csfml_var->window);
        sfRenderWindow_display(csfml_var->window);
    }
    return EXIT_SUCCESS;
}
