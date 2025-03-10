/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** destroy_everything
*/
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"
#include "../include/csfml_include.h"

void destroy_everything(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    sfSprite_destroy(texture_st->background);
    sfTexture_destroy(texture_st->texture_background);
    sfRenderWindow_destroy(window_st->window);
    free(texture_st);
    free(time_st);
    free(vector_st);
    free(window_st);
}
