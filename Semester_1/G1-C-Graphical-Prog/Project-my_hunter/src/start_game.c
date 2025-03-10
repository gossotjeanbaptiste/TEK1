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

int start_game(struct csfml_var *csfml_var)
{
    if (!csfml_var->window || !csfml_var->texture_sprite || !csfml_var->sprite
    || !csfml_var->texture_background)
        return EXIT_FAILURE;
    sfSprite_setTexture
    (csfml_var->background, csfml_var->texture_background, sfTrue);
    sfSprite_setTexture(csfml_var->sprite, csfml_var->texture_sprite, sfTrue);
    sfSprite_setPosition(csfml_var->sprite, csfml_var->position);
    sfRenderWindow_setFramerateLimit(csfml_var->window, csfml_var->framerate);
    main_loop(csfml_var);
    destroy_everything(csfml_var);
}
