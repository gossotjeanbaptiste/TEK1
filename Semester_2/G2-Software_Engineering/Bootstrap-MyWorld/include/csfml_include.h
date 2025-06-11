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
    #include <math.h>
    #define  M_PI 3.14159265358979323846
    #define MAP_X 6
    #define MAP_Y 6
    #define TILE_SIZE 64
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600
typedef struct map_creator_s {
    sfVector2f **map_2d;
    sfVector2f top_left;
    sfVector2f bottom_right;
    float grid_width;
    float grid_height;
    float offset_x;
    float offset_y;
    int z;
} map_creator_t;
// Sample 3D map
extern const int map[MAP_Y][MAP_X];
sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_2d_map(const int map[MAP_Y][MAP_X]);
int draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
//int main(int ac, char **av);
#endif /* !INCLUDED_CSFML_INCLUDE_H */
