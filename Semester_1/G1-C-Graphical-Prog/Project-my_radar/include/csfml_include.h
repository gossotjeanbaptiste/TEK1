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

#ifndef INCLUDED_CSFML_INCLUDE_H
    #define INCLUDED_CSFML_INCLUDE_H
typedef struct csfml_texture_s {
    sfSprite *sprite;
    sfTexture *texture_sprite;
    sfTexture *texture_background;
    sfSprite *background;
} csfml_texture_t;
typedef struct csmfl_time_s {
    sfTime time;
    sfClock *clock;
    float delta_time_animation;
    float delta_time_movement;
    int framerate;
    float miliseconds_animation;
    float miliseconds_movement;
} csfml_time_t;
typedef struct csfml_window_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfMouseButtonEvent event_mb;
    sfEvent event;
} csfml_window_t;
typedef struct csfml_vector_s {
    sfVector2f velocity;
    sfVector2f position;
    sfVector2f sprite_position;
    sfVector2i mouse_position;
    sfIntRect rect;
    sfFloatRect sprite_bounds;
} csfml_vector_t;

typedef struct airplane_s {
    int x1;
    int y1;
    int x2;
    int y2;
    int speed;
    int takeoff_time;
    struct airplane_s *next;
} airplane_t;

typedef struct tower_s {
    int x;
    int y;
    int radius;
    struct tower_s *next;
} tower_t;
void parse_file(const char *filename, airplane_t **airplanes,
    tower_t **towers);
void call(char *line, airplane_t **airplanes,
    tower_t **towers);
void call(char *line, airplane_t **airplanes, tower_t **towers);
void free_everything(airplane_t *airplanes, tower_t *towers);
void hitbox(void);
void parse_airplane(char *line, airplane_t **airplanes);
void parse_tower(char *line, tower_t **towers);
void var_declaration(char *path);
int start_game(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
int my_radar(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
void main_loop(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
void analyse_events(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
void mouse_click(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
void destroy_everything(csfml_texture_t *texture_st, csfml_time_t *time_st,
    csfml_vector_t *vector_st, csfml_window_t *window_st);
void call_or_use(char **av);
int randint(int min, int max);
#endif /* !INCLUDED_CSFML_INCLUDE_H */
