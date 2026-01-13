/*
** EPITECH PROJECT, 2025
** Bootstrap-MyWorld
** File description:
** create_line
*/

#include "../include/csfml_include.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfRed};
    sfVertex vertex2 = {.position = *point2, .color = sfYellow};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return vertex_array;
}
