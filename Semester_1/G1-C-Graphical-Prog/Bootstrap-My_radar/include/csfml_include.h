/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** csfml_include
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#ifndef INCLUDED_CSFML_INCLUDE_H
    #define INCLUDED_CSFML_INCLUDE_H

struct csfml_var {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfMouseButtonEvent event_mb;
    sfSprite *sprite;
    sfTexture *texture_sprite;
    sfTexture *texture_background;
    sfSprite *background;
    sfIntRect rect;
    sfClock *clock_movement;
    sfClock *clock_animation;
    sfVector2f velocity;
    sfVector2f position;
    sfVector2f sprite_position;
    sfVector2i mouse_position;
    sfFloatRect sprite_bounds;
    sfTime time_animation;
    sfTime time_movement;
    sfCircleShape *circle1;
    sfCircleShape *circle2;
    sfColor color;
    float delta_time_animation;
    float delta_time_movement;
    int framerate;
    float miliseconds_animation;
    float miliseconds_movement;
};
void analyse_events(struct csfml_var *csfml_var);
void destroy_everything(struct csfml_var *csfml_var);
int randint(int min, int max);
int main(int ac, char **av);
int start_game(struct csfml_var *csfml_var);
void var_declaration(void);
int bsmy_radar(struct csfml_var *csfml_var);
sfCircleShape *create_circle(sfVector2f position, float radius);
bool check_intersection(sfCircleShape *circle1, sfCircleShape *circle2);
void draw_circles(sfRenderWindow *window);
#endif /* !INCLUDED_CSFML_INCLUDE_H */
