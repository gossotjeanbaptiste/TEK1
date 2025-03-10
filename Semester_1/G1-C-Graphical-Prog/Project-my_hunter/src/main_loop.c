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

void main_loop(struct csfml_var *csfml_var)
{
    while (sfRenderWindow_isOpen(csfml_var->window)) {
        analyse_events(csfml_var);
        sfRenderWindow_clear(csfml_var->window, sfBlack);
        sfSprite_setTexture(csfml_var->background,
            csfml_var->texture_background, sfTrue);
        sfSprite_setTexture(csfml_var->sprite, csfml_var->texture_sprite,
            sfTrue);
        sfSprite_setTextureRect(csfml_var->sprite, csfml_var->rect);
        sfRenderWindow_drawSprite(csfml_var->window,
            csfml_var->background, NULL);
        sfRenderWindow_drawSprite(csfml_var->window, csfml_var->sprite, NULL);
        sfRenderWindow_display(csfml_var->window);
        sprite_hitbox(csfml_var);
        move_rect(csfml_var, 110, 330);
        move_sprite(csfml_var);
    }
}
