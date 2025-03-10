/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** start_game
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

int start_game(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    if (!window_st->window || !texture_st->texture_background)
        return EXIT_FAILURE;
    sfSprite_setTexture
    (texture_st->background, texture_st->texture_background, sfTrue);
    sfRenderWindow_setFramerateLimit(window_st->window, time_st->framerate);
    main_loop(texture_st, time_st, vector_st, window_st);
    destroy_everything(texture_st, time_st, vector_st, window_st);
}
