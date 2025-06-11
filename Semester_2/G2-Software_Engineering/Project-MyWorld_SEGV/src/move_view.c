/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** move_view
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>

void scroll_event(main_t *main_data)
{
    zoom_t zoom;

    zoom.delta = main_data->event.mouseWheelScroll.delta;
    if (main_data->event.type == sfEvtMouseWheelScrolled) {
        zoom.zoom_factor = 1.1f;
        zoom.view_size = sfView_getSize(main_data->view);
        zoom.window_size = sfRenderWindow_getSize(main_data->window);
        zoom.current_zoom = zoom.view_size.x / (float)zoom.window_size.x;
        if (zoom.delta > 0)
            sfView_zoom(main_data->view, 1.0f / zoom.zoom_factor);
        else
            sfView_zoom(main_data->view, zoom.zoom_factor);
        sfRenderWindow_setView(main_data->window, main_data->view);
    }
}

void move_view(main_t *main_data, view_t *viewer)
{
    if (main_data->event.type == sfEvtMouseButtonPressed &&
        main_data->event.mouseButton.button == sfMouseLeft) {
        viewer->initial_mouse_pos.x = main_data->event.mouseButton.x;
        viewer->initial_mouse_pos.y = main_data->event.mouseButton.y;
        viewer->is_dragging = 1;
    } else if (main_data->event.type == sfEvtMouseButtonReleased &&
        main_data->event.mouseButton.button == sfMouseLeft) {
        viewer->is_dragging = 0;
    }
    if (viewer->is_dragging && main_data->event.type == sfEvtMouseMoved) {
        viewer->dx =
        main_data->event.mouseMove.x - viewer->initial_mouse_pos.x;
        viewer->dy =
        main_data->event.mouseMove.y - viewer->initial_mouse_pos.y;
        sfView_move(main_data->view, (sfVector2f){- viewer->dx, - viewer->dy});
        sfRenderWindow_setView(main_data->window, main_data->view);
        viewer->initial_mouse_pos.x = main_data->event.mouseMove.x;
        viewer->initial_mouse_pos.y = main_data->event.mouseMove.y;
    }
}
