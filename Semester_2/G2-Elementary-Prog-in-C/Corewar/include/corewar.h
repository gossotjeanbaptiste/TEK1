/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Header
*/
#ifndef COREWAR
    #define COREWAR
    #include <stddef.h>
    #include <stdlib.h>
    #include "op.h"
    #define NO 0
    #define REG 1
    #define DIR2 2
    #define DIR4 4
    #define IND 3
    #define ABS(value) ((value > 0) ? (value) : (-(value)))
typedef int arg_type_t;
typedef struct prog_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int pc;
    int carry;
    long id;
    int live_call_cyle;
    int address;
    long size;
    char *content;
    int *registers;
    int last_execute;
} prog_t;

typedef struct global_s {
    long nbr_cycle_dump;
    long cycle;
    int cycles_to_die;
    int *memory;
    char *last_alive;
    int last_live_id;
    int live_calls;
    prog_t **progs;
} global_t;

typedef struct args_infos_s {
    char *dump;
    char *prog_nbr;
    char *load_addres;
    global_t *global;
} args_infos_t;

typedef struct valid_args_s {
    arg_type_t arg1;
    arg_type_t arg2;
    arg_type_t arg3;
} valid_args_t;

typedef struct cmd_s {
    int id;
    int duration;
    int has_op_code;
    int args_nbr;
    valid_args_t args_types[3];
    void (*exec_function)(global_t *, prog_t *);
} cmd_t;

/* Src */

void manage_args(int argc, char **argv, global_t *global);
int check_cmd(global_t *global, int address);
void use_cycle_loop(global_t *global);
void manage_dump_arg(char *value, args_infos_t *infos);
void execute_commands(global_t *global);
void show_winner(global_t *global);

/* Src -> Functions */

void ex_and(global_t *global, prog_t *prog);
void live(global_t *global, prog_t *prog);
void sti(global_t *global, prog_t *prog);
void zjmp(global_t *global, prog_t *prog);
void ex_xor(global_t *global, prog_t *prog);
void ex_or(global_t *global, prog_t *prog);
void aff(global_t *global, prog_t *prog);
void ex_fork(global_t *global, prog_t *prog);
void ex_lfork(global_t *global, prog_t *prog);
void ex_ld(global_t *global, prog_t *prog);
void ex_st(global_t *global, prog_t *prog);
void ldi(global_t *global, prog_t *prog);
void lldi(global_t *global, prog_t *prog);
void add(global_t *global, prog_t *prog);
void sub(global_t *global, prog_t *prog);
void lld(global_t *global, prog_t *prog);


/* Src -> Progs */

int get_progs_size(global_t *global);
int can_place_prog(global_t *global, prog_t *prog, int address);
void add_prog(global_t *global, prog_t *prog);
void sort_progs(global_t *global);
void place_progs(global_t *global);
int can_place_prog(global_t *global, prog_t *prog, int address);
int test_place(prog_t *progp, prog_t *prog, int address);

/* Src -> Progs -> Remove */

void remove_prog(global_t *global, prog_t *prog);
void remove_dead_progs(global_t *global);
void remove_all_progs(global_t *global);

/* Src -> Progs -> Valid */

int is_prog_id_valid(global_t *global, long id);
int is_prog_address_valid(global_t *global, int address);

/* Src -> Parser */

void parse_cor_file(char *file, char *prog_nbr, char *load_address,
    global_t *global);
void verify_file(char *path, char **buffer);

/* Src -> Tools */

void add_pc(int *pc, int nb);
int select_address(int address);
void write_4bytes(global_t *global, int address, int value);
void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp);

/* Src -> Tools -> Getter*/

arg_type_t get_argument_type(global_t *global, int cmd_address, int arg);
long get_4bytes_arg(global_t *global, int address);
int get_2bytes_arg(global_t *global, int address);
int get_type_size(arg_type_t type);
long get_arg_value(global_t *global, arg_type_t type,
    int address, prog_t *prog);
long get_arg_value_mod(global_t *global, arg_type_t type,
    int address, prog_t *prog);
int get_execute_address(prog_t *prog);
int get_command_duration(int id);
int get_first_valid_id(global_t *global);

static const cmd_t COMMANDS[] = {
    {1, 10, 0, 1, {{DIR4, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &live},
    {2, 5, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, &ex_ld},
    {3, 5, 1, 2, {{REG, NO, NO}, {IND, REG, NO}, {NO, NO, NO}}, &ex_st},
    {4, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, &add},
    {5, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, &sub},
    {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, &ex_and},
    {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, &ex_or},
    {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, &ex_xor},
    {9, 20, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &zjmp},
    {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG, NO}, {REG, NO, NO}}, &ldi},
    {11, 25, 1, 3, {{REG, NO, NO}, {REG, DIR2, IND}, {DIR2, REG, NO}}, &sti},
    {12, 800, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &ex_fork},
    {13, 10, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, &lld},
    {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2, NO}, {REG, NO, NO}}, &lldi},
    {15, 1000, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &ex_lfork},
    {16, 2, 1, 1, {{REG, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &aff}
};

#endif /* !COREWAR */
