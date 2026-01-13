/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** main_loop
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void main_loop(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    while (sfRenderWindow_isOpen(window_st->window)) {
        analyse_events(texture_st, time_st, vector_st, window_st);
        sfRenderWindow_clear(window_st->window, sfBlack);
        sfSprite_setTexture(texture_st->background,
            texture_st->texture_background, sfTrue);
        sfRenderWindow_drawSprite(window_st->window,
            texture_st->background, NULL);
        sfRenderWindow_display(window_st->window);
    }
}
