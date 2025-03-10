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

void destroy_everything(struct csfml_var *csfml_var)
{
    sfSprite_destroy(csfml_var->sprite);
    sfSprite_destroy(csfml_var->background);
    sfTexture_destroy(csfml_var->texture_sprite);
    sfTexture_destroy(csfml_var->texture_background);
    sfClock_destroy(csfml_var->clock_animation);
    sfClock_destroy(csfml_var->clock_movement);
    sfRenderWindow_destroy(csfml_var->window);
}
