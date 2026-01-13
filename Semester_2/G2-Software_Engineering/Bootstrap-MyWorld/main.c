/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** main
*/
#include "include/csfml_include.h"
#include "include/my.h"
#include "include/my_graphical.h"
#include "include/struct_fb.h"
#include "include/ansi_color_code.h"

extern const int map[MAP_Y][MAP_X];


static void event_handler(sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfVector2f **map_2d = create_2d_map(map);
    sfEvent event;

    window = sfRenderWindow_create
    (mode, "Centered Isometric Grid", sfResize | sfClose, NULL);
    if (!window || !map_2d)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(window)) {
        event_handler(event, window);
        sfRenderWindow_clear(window, sfWhite);
        draw_2d_map(window, map_2d);
        sfRenderWindow_display(window);
    }
    for (int y = 0; y < MAP_Y; y++)
        free(map_2d[y]);
    free(map_2d);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
