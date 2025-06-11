/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** print_my_graph_data
*/

#include <stdio.h>
#include "graph.h"

static void print_my_graph_data_recursive
(link_t *link, int *visited, int *index)
{
    if (link == NULL || visited[*index] == 1)
        return;
    visited[*index] = 1;
    printf("%d\n", link->data);
    for (int i = 0; i < link->next_count; i++) {
        (*index)++;
        print_my_graph_data_recursive(link->next[i], visited, index);
    }
}

void print_my_graph_data(link_t *graph)
{
    int visited[100] = {0};
    int index = 0;

    if (graph == NULL) {
        printf("Graph is NULL\n");
        return;
    }
    print_my_graph_data_recursive(graph, visited, &index);
}
