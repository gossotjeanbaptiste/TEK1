/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** buttons.c
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>
#include <SFML/Graphics.h>

void free_buttons(main_t *main_data)
{
    sfSprite_destroy(main_data->quit.sprite);
    sfTexture_destroy(main_data->quit.texture);
    sfSprite_destroy(main_data->new.sprite);
    sfTexture_destroy(main_data->new.texture);
    sfSprite_destroy(main_data->load.sprite);
    sfTexture_destroy(main_data->load.texture);
    sfSprite_destroy(main_data->save.sprite);
    sfTexture_destroy(main_data->save.texture);
}

void button_scale(main_t *main, button_t button, int x, int y)
{
    sfVector2i button_screen_pos = {x, y};
    sfVector2f button_world_pos = sfRenderWindow_mapPixelToCoords
    (main->window, button_screen_pos, NULL);
    sfVector2f view_size =
    sfView_getSize(sfRenderWindow_getView(main->window));
    sfVector2u window_size = sfRenderWindow_getSize(main->window);
    sfVector2f inverse_scale = {
        (float)window_size.x / view_size.x,
        (float)window_size.y / view_size.y
    };
    sfVector2f original_scale = {3, 3};
    sfVector2f final_scale = {
        original_scale.x / (inverse_scale.x),
        original_scale.y / (inverse_scale.y)
    };

    sfSprite_setPosition(button.sprite, button_world_pos);
    sfSprite_setScale(button.sprite, final_scale);
}

sfBool cont_rect(const sfFloatRect *rect, int x, int y)
{
    sfBool a;

    a = sfFloatRect_contains(rect, (float)x, (float) y);
    return a;
}

int button_hitbox(sfRenderWindow *window, main_t *main, button_t *button)
{
    sfVector2f pos;
    sfFloatRect rect_button;
    sfVector2i mouse_position_window;

    button->state = 0;
    button->rect.left = 0;
    mouse_position_window = sfMouse_getPositionRenderWindow(window);
    pos = sfRenderWindow_mapPixelToCoords
    (window, mouse_position_window, main->view);
    rect_button = sfSprite_getGlobalBounds(button->sprite);
    rect_button.width = rect_button.width;
    if (cont_rect((const sfFloatRect *)&rect_button, pos.x, pos.y)) {
        button->rect.left = 64;
        if (main->click == 1) {
            button->rect.left = 128;
            button->state = 1;
        }
    }
    return 0;
}
