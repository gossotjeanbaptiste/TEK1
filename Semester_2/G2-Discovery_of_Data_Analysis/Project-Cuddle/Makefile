##
## EPITECH PROJECT, 2025
## Cuddle
## File description:
## Makefile for the Cuddle library
##

NAME	=	libcuddle.a

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I./include
LDFLAGS	=	-lm

UTILS = src/utils
FILE = src/utils/file_utils
GROUPBY = src/utils/groupby_utils
STATS = src/utils/stats_utils
STRING = src/utils/string_utils
TYPE = src/utils/type_utils
DESCRIBE = src/df_describe
READ = src/df_read_csv
TO_TYPE = src/df_to_type

SRC	=	$(FILE)/file_utils_1.c \
		$(FILE)/file_utils_2.c \
		$(FILE)/file_utils_3.c \
		$(GROUPBY)/groupby_utils_1.c \
		$(GROUPBY)/groupby_utils_2.c \
		$(GROUPBY)/groupby_utils_3.c \
		$(STATS)/stats_utils_1.c \
		$(STATS)/stats_utils_2.c \
		$(STATS)/stats_utils_3.c \
		$(STRING)/string_utils_1.c \
		$(STRING)/string_utils_2.c \
		$(TYPE)/type_utils_1.c \
		$(TYPE)/type_utils_2.c \
		$(UTILS)/create_dataframe_utils.c \
		$(UTILS)/process_data.c \
		$(UTILS)/df_struct_utils.c \
		$(UTILS)/value_utils.c \
		$(UTILS)/sort_utils.c \
		$(UTILS)/filter_utils.c \
		$(UTILS)/apply_utils.c \
		$(DESCRIBE)/calc_std.c \
		$(DESCRIBE)/describe_column.c \
		$(DESCRIBE)/df_describe.c \
		$(DESCRIBE)/get_max.c \
		$(DESCRIBE)/get_min.c \
		$(DESCRIBE)/means.c \
		$(DESCRIBE)/print_col_stats.c \
		$(READ)/create_dataframe.c \
		$(READ)/df_read_csv.c \
		$(READ)/df_read_csv_3.c \
		$(TO_TYPE)/can_convert_to_type.c \
		$(TO_TYPE)/copy_dataframe_structure.c \
		$(TO_TYPE)/df_to_type.c \
		src/df_write_csv.c \
		src/df_apply.c \
		src/df_filter.c \
		src/df_free.c \
		src/df_get_unique_values_utils.c \
		src/df_get_unique_values.c \
		src/df_get_value.c \
		src/df_get_values.c \
		src/df_groupby.c \
		src/df_head_utils.c \
		src/df_head.c \
		src/df_info.c \
		src/df_read_utils.c \
		src/df_shape.c \
		src/df_sort.c \
		src/df_tail.c \
		src/df_utils.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C tests clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all


run: all
	$(MAKE) -C tests run

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make for have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

.PHONY:	all clean fclean re
