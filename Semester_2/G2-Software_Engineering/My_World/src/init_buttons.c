/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** init_button
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>
#include <SFML/Graphics.h>


void init_button_load(main_t *main)
{
    char *a;

    a = "assets/load_button.png";
    main->load.texture = sfTexture_createFromFile(a, NULL);
    main->load.sprite = sfSprite_create();
    sfSprite_setTexture(main->load.sprite, main->load.texture, sfTrue);
    main->load.rect.top = 0;
    main->load.rect.left = 0;
    main->load.rect.width = 64;
    main->load.rect.height = 32;
}

void init_button_new(main_t *main)
{
    char *a;

    a = "assets/new_button.png";
    main->new.texture = sfTexture_createFromFile(a, NULL);
    main->new.sprite = sfSprite_create();
    sfSprite_setTexture(main->new.sprite, main->new.texture, sfTrue);
    main->new.rect.top = 0;
    main->new.rect.left = 0;
    main->new.rect.width = 64;
    main->new.rect.height = 32;
}

void init_button_quit(main_t *main)
{
    char *a;

    a = "assets/quit_button.png";
    main->quit.texture = sfTexture_createFromFile(a, NULL);
    main->quit.sprite = sfSprite_create();
    sfSprite_setTexture(main->quit.sprite, main->quit.texture, sfTrue);
    main->quit.rect.top = 0;
    main->quit.rect.left = 0;
    main->quit.rect.width = 64;
    main->quit.rect.height = 32;
}

void init_button_save(main_t *main)
{
    char *a;

    a = "assets/save_button.png";
    main->save.texture = sfTexture_createFromFile(a, NULL);
    main->save.sprite = sfSprite_create();
    sfSprite_setTexture(main->save.sprite, main->save.texture, sfTrue);
    main->save.rect.top = 0;
    main->save.rect.left = 0;
    main->save.rect.width = 64;
    main->save.rect.height = 32;
}

void init_all_buttons(main_t *main_data)
{
    init_button_load(main_data);
    init_button_new(main_data);
    init_button_quit(main_data);
    init_button_save(main_data);
}
