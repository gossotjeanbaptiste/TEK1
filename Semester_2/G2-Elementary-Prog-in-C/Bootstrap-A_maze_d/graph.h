/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** graph
*/

#ifndef INCLUDED_GRAPH_H
    #define INCLUDED_GRAPH_H
typedef struct link {
    int data;
    struct link **next;
    int next_count;
} link_t;
void connect_links(link_t *link1, link_t *link2);
link_t *create_link(int data);
void print_link(link_t *link);
void connect_links(link_t *link1, link_t *link2);
void print_data_of_connected_links(link_t *link);
void print_my_graph_data(link_t *graph);
#endif
