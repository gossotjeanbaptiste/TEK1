/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** csfml_include
*/


#ifndef INCLUDED_CSFML_INCLUDE_H
    #define INCLUDED_CSFML_INCLUDE_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Mouse.h>
    #include <stdlib.h>
    #include <stdio.h>
    #define MAP_X 5
    #define MAP_Y 5

typedef struct button {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    sfVector2f scale;
} button_t;

typedef struct map_s {
    int size;
    int **map;
    sfVector2f ***points;
} map_t;


typedef struct main {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfView *view;
    sfVertexArray *vertexArray;
    int z;
    button_t play;
    int click;
} main_t;

typedef struct vector_point {
    sfVector2f p1;
    sfVector2f p2;
    sfVector2f p3;
    sfVector2f p4;
    sfVector2f p5;
    sfVector2f p6;
    sfVector2f p7;
} point_t;

typedef struct move_view {
    sfRenderWindow* window;
    sfView* view;
    sfEvent event;
    sfVector2i initial_mouse_pos;
    int is_dragging;
    int dx;
    int dy;
} view_t;

typedef struct zoom {
    float delta;
    float zoom_factor;
    sfVector2f view_size;
    sfVector2u window_size;
    float current_zoom;
} zoom_t;

typedef struct circle {
    sfCircleShape *circle;
    sfVector2f cursor_pos;
    float threshold;
    sfVector2i mouse_pos_i;
} circle_t;

typedef struct updater {
    sfVector2i button_screen_pos;
    sfVector2f button_world_pos;
    sfVector2f view_size;
    sfVector2u window_size;
    sfVector2f inverse_scale;
    sfVector2f original_scale;
    sfVector2f final_scale;
} updater_t;

int main(int ac, char **av);
int my_world(void);
int loop(void);
int init_map(map_t *map, int size);
int init_points(map_t *map);
void event_and_update(main_t *main_data, map_t *map);
void adder(sfVector2f ***points, sfVertexArray *vertexArray, map_t *map);
void move_view(main_t *main_data, view_t *viewer);
void scroll_event(main_t *main_data);
void init_button_play(main_t *main);
int button_play_hitbox(sfRenderWindow *window, main_t *main);
void projector_iso_point(map_t *map);
#endif /* !INCLUDED_CSFML_INCLUDE_H */
