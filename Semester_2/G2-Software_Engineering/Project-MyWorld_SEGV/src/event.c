/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** event
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>


static void close_window(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

static int is_cursor_near_point
(sfVector2f cursor_pos, sfVector2f point, float threshold)
{
    return ((my_compute_power_rec(cursor_pos.x - point.x, 2)
    + my_compute_power_rec(cursor_pos.y - point.y, 2))
    <= my_compute_power_rec(threshold, 2));
}

static void verify_and_create
(circle_t *circles, main_t *main_data, map_t *map, int y, int x)
{
    if (is_cursor_near_point(circles->cursor_pos,
        map->points[y][x][0], circles->threshold)) {
        circles->circle = sfCircleShape_create();
        sfCircleShape_setRadius(circles->circle, 5);
        sfCircleShape_setPosition(circles->circle,
            (sfVector2f){map->points[y][x][0].x - 5,
            map->points[y][x][0].y - 5});
        sfCircleShape_setFillColor(circles->circle, sfRed);
        sfRenderWindow_drawCircleShape
        (main_data->window, circles->circle, NULL);
        sfCircleShape_destroy(circles->circle);
    }
}

static void create_circle_on_cross(main_t *main_data, map_t *map)
{
    circle_t *circles = malloc(sizeof(circle_t));

    circles->mouse_pos_i = sfMouse_getPositionRenderWindow(main_data->window);
    circles->cursor_pos = sfRenderWindow_mapPixelToCoords
    (main_data->window, circles->mouse_pos_i,
        sfRenderWindow_getView(main_data->window));
    circles->threshold = 10.0f;
    for (int y = 0; y <= map->size; y++) {
        for (int x = 0; x <= map->size; x++) {
            verify_and_create(circles, main_data, map, y, x);
        }
    }
    free(circles);
}

static void updater(main_t *main_data, map_t *map)
{
    updater_t updater;

    updater.button_screen_pos = (sfVector2i){396, 400};
    updater.button_world_pos = sfRenderWindow_mapPixelToCoords
    (main_data->window, updater.button_screen_pos, NULL);
    sfSprite_setPosition(main_data->play.sprite, updater.button_world_pos);
    updater.view_size = sfView_getSize
    (sfRenderWindow_getView(main_data->window));
    updater.window_size = sfRenderWindow_getSize(main_data->window);
    updater.inverse_scale = (sfVector2f){
        (float)updater.window_size.x / updater.view_size.x,
        (float)updater.window_size.y / updater.view_size.y
    };
    updater.original_scale = (sfVector2f){2, 2};
    updater.final_scale = (sfVector2f){
        updater.original_scale.x * updater.inverse_scale.x,
        updater.original_scale.y * updater.inverse_scale.y
    };
    sfSprite_setScale(main_data->play.sprite, updater.final_scale);
    button_play_hitbox(main_data->window, main_data);
    sfRenderWindow_clear(main_data->window, sfWhite);
    sfVertexArray_clear(main_data->vertexArray);
    adder(map->points, main_data->vertexArray, map);
    sfRenderWindow_drawVertexArray(main_data->window,
    main_data->vertexArray, NULL);
    create_circle_on_cross(main_data, map);
    sfSprite_setTextureRect(main_data->play.sprite, main_data->play.rect);
    sfRenderWindow_drawSprite(main_data->window, main_data->play.sprite, NULL);
    sfRenderWindow_display(main_data->window);
}

void mousse_is_pressed(main_t *main)
{
    if (main->event.type == sfEvtMouseButtonPressed)
        main->click = 1;
    else
        main->click = 0;
}

void event_and_update(main_t *main_data, map_t *map)
{
    view_t *viewer = malloc(sizeof(view_t));

    viewer->initial_mouse_pos.x = 0;
    viewer->initial_mouse_pos.y = 0;
    viewer->is_dragging = 0;
    while (sfRenderWindow_isOpen(main_data->window)) {
        while (sfRenderWindow_pollEvent
            (main_data->window, &main_data->event)) {
            close_window(main_data->window, main_data->event);
            scroll_event(main_data);
            move_view(main_data, viewer);
        }
        sfRenderWindow_clear(main_data->window, sfBlack);
        sfVertexArray_clear(main_data->vertexArray);
        projector_iso_point(map);
        adder(map->points, main_data->vertexArray, map);
        sfRenderWindow_drawVertexArray
        (main_data->window, main_data->vertexArray, NULL);
        create_circle_on_cross(main_data, map);
        sfRenderWindow_display(main_data->window);
    }
    free(viewer);
}
