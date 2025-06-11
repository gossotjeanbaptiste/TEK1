/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** select_iso_point
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>

sfCircleShape* create_circle_around_mouse(sfRenderWindow* window, float radius)
{
    sfVector2i mouse_pos_i = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = sfRenderWindow_mapPixelToCoords
    (window, mouse_pos_i, sfRenderWindow_getView(window));
    sfCircleShape* circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition
    (circle, (sfVector2f){mouse_pos_f.x - radius, mouse_pos_f.y - radius});
    sfCircleShape_setFillColor(circle, sfRed);
    return circle;
}
