/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** var_declaration
*/
//a_or_p_t *a_or_p_st = rdr_parser(path);
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"
#include "../include/my_graphical.h"

void var_declaration(char *path)
{
    csfml_texture_t *texture_st = malloc(sizeof(csfml_texture_t));
    csfml_window_t *window_st = malloc(sizeof(csfml_window_t));
    csfml_time_t *time_st = malloc(sizeof(csfml_time_t));
    csfml_vector_t *vector_st = malloc(sizeof(csfml_vector_t));
    airplane_t *airplane = malloc(sizeof(airplane_t));
    tower_t *tower = malloc(sizeof(tower_t));

    window_st->mode = (sfVideoMode){1920, 1080, 32};
    window_st->window = sfRenderWindow_create(window_st->mode,
    "My_Hunter", sfResize | sfClose, NULL);
    time_st->clock = sfClock_create();
    texture_st->texture_background = sfTexture_createFromFile(
        "assets/background/world_map.jpg", NULL);
    texture_st->background = sfSprite_create();
    vector_st->position = (sfVector2f){0, randint(50, 1000)};
    time_st->framerate = 24;
    parse_file(path, &airplane, &tower);
    my_radar(texture_st, time_st, vector_st, window_st);
}
