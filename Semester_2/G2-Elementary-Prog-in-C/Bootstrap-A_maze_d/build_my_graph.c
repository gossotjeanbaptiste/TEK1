/*
** EPITECH PROJECT, 2025
** Bootstrap-A_maze_d
** File description:
** build_my_graph
*/

#include <stdlib.h>
#include "graph.h"

link_t *build_my_graph(void)
{
    link_t *link42 = create_link(42);
    link_t *link60012 = create_link(60012);
    link_t *link30012 = create_link(30012);
    link_t *link48 = create_link(48);
    link_t *link50012 = create_link(50012);
    link_t *link3 = create_link(3);
    link_t *link98 = create_link(98);
    link_t *link8 = create_link(8);

    if (!link42 || !link60012 || !link30012 || !link48
        || !link50012 || !link3 || !link98 || !link8)
        return NULL;
    connect_links(link42, link60012);
    connect_links(link42, link48);
    connect_links(link60012, link30012);
    connect_links(link48, link50012);
    connect_links(link50012, link3);
    connect_links(link3, link98);
    connect_links(link3, link8);
    return link42;
}
