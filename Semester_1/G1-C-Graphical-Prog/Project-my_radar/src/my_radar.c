/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** my_radar
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

int my_radar(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    if (!window_st->window || !texture_st->texture_background)
        return EXIT_FAILURE;
    else
        start_game(texture_st, time_st, vector_st, window_st);
    return EXIT_SUCCESS;
}
