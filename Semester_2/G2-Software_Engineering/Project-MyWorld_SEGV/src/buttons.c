/*
** EPITECH PROJECT, 2025
** Project-MyWorld
** File description:
** add_line
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include <math.h>
#include <SFML/Graphics.h>

sfBool cont_rect(const sfFloatRect *rect, int x, int y)
{
    sfBool a;

    a = sfFloatRect_contains(rect, (float)x, (float) y);
    return a;
}

void init_button_play(main_t *main)
{
    char *a = "assets/button.png";

    main->play.texture = sfTexture_createFromFile(a, NULL);
    main->play.sprite = sfSprite_create();
    sfSprite_setTexture(main->play.sprite, main->play.texture, sfTrue);
    main->play.rect.top = 0;
    main->play.rect.left = 0;
    main->play.rect.width = 64;
    main->play.rect.height = 32;
}

int button_play_hitbox(sfRenderWindow *window, main_t *main)
{
    sfVector2i pos;
    sfFloatRect rect_button;

    main->play.rect.left = 0;
    pos = sfMouse_getPositionRenderWindow(window);
    rect_button = sfSprite_getGlobalBounds(main->play.sprite);
    rect_button.width = rect_button.width / 3;
    if (cont_rect((const sfFloatRect *)&rect_button, pos.x, pos.y)) {
        main->play.rect.left = 64;
        if (main->click == 1)
            main->play.rect.left = 128;
    }
    return 0;
}
