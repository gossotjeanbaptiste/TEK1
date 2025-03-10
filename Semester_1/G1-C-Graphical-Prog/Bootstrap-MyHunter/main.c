/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** main
*/
#include "include/csfml_include.h"
#include "include/my.h"
#include "include/my_graphical.h"
#include "include/struct_fb.h"
void move_rect(struct csfml_var *csfml_var, int offset, int max_value);

int main(void)
{
    struct csfml_var csfml_var;

    csfml_var.mode = (sfVideoMode){800, 600, 32};
    csfml_var.rect.top = 0;
    csfml_var.rect.left = 0;
    csfml_var.rect.height = 110;
    csfml_var.rect.width = 110;
    csfml_var.velocity = (sfVector2f){5, 5};
    csfml_var.window = sfRenderWindow_create(csfml_var.mode,
    "Bootstrap My_Hunter", sfResize | sfClose, NULL);
    csfml_var.texture = sfTexture_createFromFile(
        "src/my_hunter_spritesheet.png", NULL);
    csfml_var.sprite = sfSprite_create();
    if (!csfml_var.window || !csfml_var.texture || !csfml_var.sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(csfml_var.sprite, csfml_var.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(csfml_var.window, 30);
    main_loop(&csfml_var);
    sfSprite_destroy(csfml_var.sprite);
    sfTexture_destroy(csfml_var.texture);
    sfRenderWindow_destroy(csfml_var.window);
    return EXIT_SUCCESS;
}

void main_loop(struct csfml_var *csfml_var)
{
    while (sfRenderWindow_isOpen(csfml_var->window)) {
        analyse_events(csfml_var);
        sfRenderWindow_clear(csfml_var->window, sfBlack);
        sfSprite_setTexture(csfml_var->sprite, csfml_var->texture, sfTrue);
        sfSprite_setTextureRect(csfml_var->sprite, csfml_var->rect);
        sfRenderWindow_drawSprite(csfml_var->window, csfml_var->sprite, NULL);
        sfRenderWindow_display(csfml_var->window);
        move_rect(csfml_var, 110, 330);
    }
}

void analyse_events(struct csfml_var *csfml_var)
{
    while (sfRenderWindow_pollEvent(csfml_var->window, &csfml_var->event)) {
        if (csfml_var->event.type == sfEvtClosed) {
            sfRenderWindow_close(csfml_var->window);
        }
    }
}

void move_rect(struct csfml_var *csfml_var, int offset, int max_value)
{
    if (csfml_var->rect.left < max_value)
        csfml_var->rect.left += offset;
    else
        csfml_var->rect.left = 0;
}
