/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** analyse_events
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/my_graphical.h"
#include "../include/struct_fb.h"

void analyse_events(struct csfml_var *csfml_var)
{
    while (sfRenderWindow_pollEvent(csfml_var->window, &csfml_var->event)) {
        if (csfml_var->event.type == sfEvtClosed)
            sfRenderWindow_close(csfml_var->window);
    }
}

