/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** manage_mouse_click
*/
#include "include/csfml_include.h"
#include "include/my.h"
#include "include/my_graphical.h"
#include "include/struct_fb.h"

void manage_mouse_click(struct csfml_var *csfml_var)
{
    printf("Mouse x=%d y=%d\n", csfml_var->event.mouseButton.x,
    csfml_var->event.mouseButton.y);
}
