/*
** EPITECH PROJECT, 2024
** Bootstrap-My_radar
** File description:
** create_circle
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    if (!circle)
        return NULL;
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, sfTransparent);
    return circle;
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos1 = sfCircleShape_getPosition(c1);
    sfVector2f pos2 = sfCircleShape_getPosition(c2);
    float radius1 = sfCircleShape_getRadius(c1);
    float radius2 = sfCircleShape_getRadius(c2);
    float dx = (pos1.x + radius1) - (pos2.x + radius2);
    float dy = (pos1.y + radius1) - (pos2.y + radius2);
    float distance = sqrt((dx * dx) + (dy * dy));

    return distance <= (radius1 + radius2);
}

void draw_circles(sfRenderWindow *window)
{
    sfVector2f position1 = {100, 100};
    sfVector2f position2 = {150, 150};
    float radius1 = 50;
    float radius2 = 50;
    sfCircleShape *circle1 = create_circle(position1, radius1);
    sfCircleShape *circle2 = create_circle(position2, radius2);

    if (check_intersection(circle1, circle2)) {
        sfCircleShape_setFillColor(circle1, sfWhite);
        sfCircleShape_setFillColor(circle2, sfWhite);
    }
    sfRenderWindow_drawCircleShape(window, circle1, NULL);
    sfRenderWindow_drawCircleShape(window, circle2, NULL);
    sfCircleShape_destroy(circle1);
    sfCircleShape_destroy(circle2);
}
