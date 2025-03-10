/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** var_declaration
*/
#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"
#include "../include/my_graphical.h"

void var_declaration(void)
{
    struct csfml_var csfml_var;
    
    csfml_var.mode = (sfVideoMode){1920, 1080, 32};
    csfml_var.window = sfRenderWindow_create(csfml_var.mode,
    "Bootstrap My_Radar", sfResize | sfClose, NULL);
    csfml_var.framerate = 24;
    bsmy_radar(&csfml_var);
}
