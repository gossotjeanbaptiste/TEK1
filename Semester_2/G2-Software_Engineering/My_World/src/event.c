/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** event
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>


static void close_window(sfRenderWindow* window, sfEvent event, main_t *main)
{
    if (event.type == sfEvtClosed || main->quit.state == 1)
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
(circle_t *circles, main_t *main_data, int y, int x)
{
    if (is_cursor_near_point(circles->cursor_pos,
        main_data->points[y][x][0], circles->threshold)) {
        circles->circle = sfCircleShape_create();
        sfCircleShape_setRadius(circles->circle, 5);
        sfCircleShape_setPosition(circles->circle,
            (sfVector2f){main_data->points[y][x][0].x - 5,
            main_data->points[y][x][0].y - 5});
        sfCircleShape_setFillColor(circles->circle, sfRed);
        sfRenderWindow_drawCircleShape
        (main_data->window, circles->circle, NULL);
        sfCircleShape_destroy(circles->circle);
    }
}

void mousse_is_pressed(main_t *main)
{
    if (main->event.type == sfEvtMouseButtonPressed) {
        main->click = 1;
    } else {
        main->click = 0;
    }
}

static void create_circle_on_cross(main_t *main_data)
{
    circle_t *circles = malloc(sizeof(circle_t));

    circles->mouse_pos_i = sfMouse_getPositionRenderWindow(main_data->window);
    circles->cursor_pos = sfRenderWindow_mapPixelToCoords
    (main_data->window, circles->mouse_pos_i,
        sfRenderWindow_getView(main_data->window));
    circles->threshold = 10.0f;
    for (int y = 0; y <= 11; y++) {
        for (int x = 0; x <= 11; x++) {
            verify_and_create(circles, main_data, y, x);
        }
    }
    free(circles);
}

void update_buttons(main_t *main_data)
{
    button_scale(main_data, main_data->quit, 0, 0);
    button_hitbox(main_data->window, main_data, &main_data->quit);
    sfSprite_setTextureRect(main_data->quit.sprite, main_data->quit.rect);
    sfRenderWindow_drawSprite(main_data->window, main_data->quit.sprite, NULL);
    button_scale(main_data, main_data->new, 0, 96);
    button_hitbox(main_data->window, main_data, &main_data->new);
    sfSprite_setTextureRect(main_data->new.sprite, main_data->new.rect);
    sfRenderWindow_drawSprite(main_data->window, main_data->new.sprite, NULL);
    button_scale(main_data, main_data->load, 0, 192);
    button_hitbox(main_data->window, main_data, &main_data->load);
    sfSprite_setTextureRect(main_data->load.sprite, main_data->load.rect);
    sfRenderWindow_drawSprite(main_data->window, main_data->load.sprite, NULL);
    button_scale(main_data, main_data->save, 0, 288);
    button_hitbox(main_data->window, main_data, &main_data->save);
    sfSprite_setTextureRect(main_data->save.sprite, main_data->save.rect);
    sfRenderWindow_drawSprite(main_data->window, main_data->save.sprite, NULL);
}

static void updater(main_t *main_data)
{
    sfRenderWindow_clear(main_data->window, sfWhite);
    sfVertexArray_clear(main_data->vertexArray);
    adder(main_data->points, main_data->vertexArray);
    sfRenderWindow_drawVertexArray(main_data->window,
    main_data->vertexArray, NULL);
    create_circle_on_cross(main_data);
    update_buttons(main_data);
    sfRenderWindow_display(main_data->window);
}

void event_and_update(main_t *main_data)
{
    view_t *viewer = malloc(sizeof(view_t));

    viewer->initial_mouse_pos.x = 0;
    viewer->initial_mouse_pos.y = 0;
    viewer->is_dragging = 0;
    main_data->click = 0;
    while (sfRenderWindow_isOpen(main_data->window)) {
        while (sfRenderWindow_pollEvent
            (main_data->window, &main_data->event)) {
            close_window(main_data->window, main_data->event, main_data);
            scroll_event(main_data);
            mousse_is_pressed(main_data);
            move_view(main_data, viewer);
        }
        updater(main_data);
    }
    free(viewer);
}
