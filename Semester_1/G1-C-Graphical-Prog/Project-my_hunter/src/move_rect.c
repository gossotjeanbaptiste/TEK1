/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** move_rect
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void move_rect(struct csfml_var *csfml_var, int offset, int max_value)
{
    csfml_var->time_animation =
    sfClock_getElapsedTime(csfml_var->clock_animation);
    csfml_var->delta_time_animation = 1000.0 / csfml_var->framerate;
    csfml_var->miliseconds_animation =
    sfTime_asMilliseconds(csfml_var->time_animation);
    if (csfml_var->miliseconds_animation > csfml_var->delta_time_animation) {
        csfml_var->rect.left += offset;
        if (csfml_var->rect.left >= max_value)
            csfml_var->rect.left = 0;
        sfClock_restart(csfml_var->clock_animation);
    }
}
