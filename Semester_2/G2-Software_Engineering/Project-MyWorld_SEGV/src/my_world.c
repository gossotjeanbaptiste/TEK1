/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** my_world
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>


sfVector2f project_iso_point(int x, int y, int z)
{
    float angle_x = 45.0f * M_PI / 180.0f;
    float angle_y = 35.0f * M_PI / 180.0f;
    sfVector2f point2d;
    sfVector3f point3d = {(float)x, (float)y, (float)z};

    point2d.x = cos(angle_x) * point3d.x - cos(angle_x) * point3d.y;
    point2d.y = sin(angle_y) * point3d.y + sin(angle_y) *
    point3d.x - point3d.z;
    return point2d;
}

void init_windows(main_t *main)
{
    sfVideoMode mode = {1920, 1080, 32};

    main->window = sfRenderWindow_create
    (mode, "Isometric Map", sfResize | sfClose, NULL);
    if (!main->window) {
        return;
    }
    sfRenderWindow_setFramerateLimit(main->window, 60);
    main->view = sfView_create();
    sfView_setSize(main->view, (sfVector2f){(float)mode.width,
        (float)mode.height});
    sfView_setCenter(main->view, (sfVector2f){0, 0});
    sfRenderWindow_setView(main->window, main->view);
}

void projector_iso_point(map_t *map)
{
    for (int y = 0; y < map->size; y++) {
        for (int x = 0; x < map->size; x++) {
            if (y < map->size && x < map->size)
            map->points[y][x][0] = project_iso_point
            (x * 64, y * 64, 0);
            map->points[y][x][1] = project_iso_point
            (x * 64, y * 64, map->map[y][x] * 64);
        }
    }
}

int my_world(void)
{
    main_t *main_data = malloc(sizeof(main_t));
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL || main_data == NULL || init_map(map, 12) == 84 || init_points(map) == 84)
        return 84;
    main_data->vertexArray = sfVertexArray_create();
    init_windows(main_data);
    init_button_play(main_data);
    main_data->clock = sfClock_create();
    sfVertexArray_setPrimitiveType(main_data->vertexArray, sfLines);
    projector_iso_point(map);
    event_and_update(main_data, map);
    sfVertexArray_destroy(main_data->vertexArray);
    sfRenderWindow_destroy(main_data->window);
    sfClock_destroy(main_data->clock);
    sfView_destroy(main_data->view);
    free_int_array(map->map);
    free(map);
    free(main_data);
    return 0;
}
