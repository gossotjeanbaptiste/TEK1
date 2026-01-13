/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** move_sprite
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void move_sprite(struct csfml_var *csfml_var)
{
    csfml_var->time_movement =
    sfClock_getElapsedTime(csfml_var->clock_movement);
    csfml_var->delta_time_movement = 1000.0 / csfml_var->framerate;
    csfml_var->miliseconds_movement =
    sfTime_asMilliseconds(csfml_var->time_movement);
    if (csfml_var->miliseconds_movement > csfml_var->delta_time_movement) {
        csfml_var->velocity = (sfVector2f){randint(8, 30), randint(-15, 30)};
        sfSprite_move(csfml_var->sprite, csfml_var->velocity);
        sfClock_restart(csfml_var->clock_movement);
    }
}
