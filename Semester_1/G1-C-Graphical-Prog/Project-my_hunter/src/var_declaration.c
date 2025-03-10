/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** var_declaration
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"
#include "../include/my_graphical.h"

void var_declaration(void)
{
    struct csfml_var csfml_var;

    csfml_var.mode = (sfVideoMode){1920, 1080, 32};
    csfml_var.rect.top = 0;
    csfml_var.rect.left = 0;
    csfml_var.rect.height = 110;
    csfml_var.rect.width = 110;
    csfml_var.window = sfRenderWindow_create(csfml_var.mode,
    "My_Hunter", sfResize | sfClose, NULL);
    csfml_var.clock_animation = sfClock_create();
    csfml_var.clock_movement = sfClock_create();
    csfml_var.texture_background = sfTexture_createFromFile(
        "assets/background/background_3.png", NULL);
    csfml_var.texture_sprite = sfTexture_createFromFile(
        "assets/sprite/my_hunter_spritesheet.png", NULL);
    csfml_var.background = sfSprite_create();
    csfml_var.sprite = sfSprite_create();
    csfml_var.position = (sfVector2f){0, randint(50, 1000)};
    csfml_var.framerate = 24;
    my_hunter(&csfml_var);
}
