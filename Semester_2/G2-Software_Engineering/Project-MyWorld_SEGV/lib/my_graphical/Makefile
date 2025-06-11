##
## EPITECH PROJECT, 2024
## B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
## File description:
## Makefile of lib/my
##

SRC 	= 	framebuffer.c	\
			my_put_pixel.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_graphical.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../
	cp my_graphical.h ../../include/
	cp struct_fb.h ../../include/
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
