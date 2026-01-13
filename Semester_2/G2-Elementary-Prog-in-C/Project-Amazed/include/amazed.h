/*
** EPITECH PROJECT, 2025
** Project-Amazed
** File description:
** amazed
*/

#ifndef INCLUDED_AMAZED_H
    #define INCLUDED_AMAZED_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdbool.h>
typedef struct Node {
    int x;
    int y;
    float cost;
    float heuristic;
    struct Node *parent;
} node_t;

typedef struct {
    node_t **nodes;
    int size;
    int capacity;
} priority_queue_t;

typedef struct {
    node_t **nodes;
    int size;
    int capacity;
} node_list_t;

typedef struct {
    int **grid;
    int width;
    int height;
} graph_t;
#endif
