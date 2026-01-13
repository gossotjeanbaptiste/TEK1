/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** analyse_events
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void analyse_events(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    while (sfRenderWindow_pollEvent(window_st->window, &window_st->event)) {
        if (window_st->event.type == sfEvtClosed)
            sfRenderWindow_close(window_st->window);
        if (window_st->event.type == sfEvtMouseButtonPressed) {
            vector_st->mouse_position =
            sfMouse_getPositionRenderWindow(window_st->window);
            mouse_click(texture_st, time_st, vector_st, window_st);
        }
    }
}

void mouse_click(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st)
{
    if (window_st->event_mb.button == sfMouseLeft) {
        vector_st->sprite_position = sfSprite_getPosition(texture_st->sprite);
    }
}
