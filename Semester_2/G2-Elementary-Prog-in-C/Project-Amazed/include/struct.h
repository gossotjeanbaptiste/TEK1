/*
** EPITECH PROJECT, 2025
** Project-Amazed
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct room room_t;

typedef struct connection {
    room_t *room;
    struct connection *next;
} connection_t;

typedef struct connection_list_s {
    char *room1;
    char *room2;
    struct connection_list_s *next;
} connection_list_t;

typedef struct room {
    char *data;
    int x;
    int y;
    connection_t *connections;
} room_t;

typedef struct room_list {
    room_t *room;
    struct room_list *next;
} room_list_t;

typedef struct memory {
    char *room_visited;
    struct memory *next;
} memory_t;

typedef struct stack_node {
    room_t *room;
    struct stack_node *next;
} stack_node_t;

typedef struct robot_s {
    int nb;
    int position;
    struct robot_s *next;
} robot_t;

typedef struct maze_s {
    int nb_robots;
    int start_nb;
    int end_nb;
    char *start_name;
    char *end_name;
    int next_is_start;
    int next_is_end;
    room_list_t *room_list;
    connection_list_t *connection_list;
} maze_t;

room_t *create_room(char *data, int x, int y);
int add_room_to_list(room_list_t **list, room_t *room);
int connect_rooms(maze_t *maze, room_list_t *list, char *name1, char *name2);
room_list_t *rrl(room_list_t *list);
void print_maze(maze_t *maze);
void push_connection(connection_list_t **connection, char *a, char *b);
int is_visited(memory_t *memory, char *room_name);
int register_room(memory_t **memory, char *room_nb);
void parcour(maze_t *maze, room_t *start_room, memory_t *memory);
int parse_input(maze_t *maze);
robot_t *generate_robot_list(maze_t *maze);
room_list_t *rrl(room_list_t *list);
void print_maze(maze_t *maze);
#endif /* ifndef STRUCT_H */
