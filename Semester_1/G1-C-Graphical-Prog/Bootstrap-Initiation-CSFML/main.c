/*
** EPITECH PROJECT, 2024
** Bootstrap-Initiation-CSFML
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <stdlib.h>

typedef struct sfMusic sfMusic;

int main() 
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    sfMusic music = sfMusic_createFromFile("src/Luidji - 488 (Prod. MNSD & Pee Magnum).mp3");
    /* Create the main window */
    window = sfRenderWindow_create(mode, "ELIOOOTTTTTTTTTTTT", sfResize | sfClose, NULL);
    if (!window) {
        return EXIT_FAILURE;
    }
    texture = sfTexture_createFromFile("src/eliott.jpeg", NULL);
    if (!texture) {
        return EXIT_FAILURE;
    }
    sfMusic_play(music);
    if (!music) {
        return EXIT_FAILURE;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

