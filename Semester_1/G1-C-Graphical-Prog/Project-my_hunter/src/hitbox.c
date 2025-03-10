/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** hitbox
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void sprite_hitbox(struct csfml_var *csfml_var)
{
    csfml_var->sprite_bounds = sfSprite_getGlobalBounds(csfml_var->sprite);
    csfml_var->sprite_position = sfSprite_getPosition(csfml_var->sprite);
    if (csfml_var->sprite_position.x > 1900 ||
    csfml_var->sprite_position.y > 1020 ||
    csfml_var->sprite_position.x < -50 ||
    csfml_var->sprite_position.y < -50) {
        recreate_sprite(csfml_var);
    }
    if (sfFloatRect_contains
    (&csfml_var->sprite_bounds, csfml_var->mouse_position.x,
    csfml_var->mouse_position.y)) {
        recreate_sprite(csfml_var);
    }
}

void recreate_sprite(struct csfml_var *csfml_var)
{
    sfSprite_destroy(csfml_var->sprite);
    csfml_var->position = (sfVector2f){0, randint(50, 1000)};
    csfml_var->sprite = sfSprite_create();
    if (!csfml_var->sprite) {
        mini_printf("Failed to create sprite\n");
        return;
    }
    sfSprite_setTexture(csfml_var->sprite, csfml_var->texture_sprite, sfTrue);
    sfSprite_setPosition(csfml_var->sprite, csfml_var->position);
}
