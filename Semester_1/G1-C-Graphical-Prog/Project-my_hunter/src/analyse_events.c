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

void analyse_events(struct csfml_var *csfml_var)
{
    while (sfRenderWindow_pollEvent(csfml_var->window, &csfml_var->event)) {
        if (csfml_var->event.type == sfEvtClosed)
            sfRenderWindow_close(csfml_var->window);
        if (csfml_var->event.type == sfEvtMouseButtonPressed) {
            csfml_var->mouse_position =
            sfMouse_getPositionRenderWindow(csfml_var->window);
            mouse_click(csfml_var);
        }
    }
}

void mouse_click(struct csfml_var *csfml_var)
{
    if (csfml_var->event_mb.button == sfMouseLeft) {
        csfml_var->sprite_position = sfSprite_getPosition(csfml_var->sprite);
        sprite_hitbox(csfml_var);
    }
}
