##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a
PROJECT_NAME = bs_rf
MY_LIB = -lmy
CFLAGS = -Wall -Wextra -Wunused -Wimplicit -O3
SRC = $(wildcard *.c) $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCL = -I include/
LIB_COMP = -L ./ $(MY_LIB)

all: libmy.a part_one part_two part_three

start :
		mv gitignore.txt .gitignore
		mv src/project.c src/$(PROJECT_NAME).c

libmy.a:
		cd lib/my && make
		@echo "libmy.a has been compiled."

compile: $(OBJ)
		gcc -o $(PROJECT_NAME) $(OBJ) $(INCL) $(LIB_COMP) $(CFLAGS)

clean:
		cd lib/my && make clean
		rm -f $(OBJ)

fclean: clean
		rm -f a.out
		rm -f $(LIB)
		rm -f $(PROJECT_NAME)
		rm -f *~
		rm -f src/*~
		rm -f lib/my/libmy.a
		rm -f lib/my/*.o
		rm -f lib/my/*~
		rm -f coding-style-reports.log
		rm -f *.gcno
		rm -f *.gcda
		rm -f unit_tests
		rm -f *.out
		rm -f *#
		rm -f *.yolo
		rm -f part1/step1/write-some-text
		rm -f part1/step2/write-a-number-as-text
		rm -f part1/step3/write-a-number-as-int
		rm -f part1/step4/without-padding
		rm -f part1/step5/with-padding
		rm -f part2/step1/yolotron-asm
		rm -f part2/step2/yolotron-vm
		rm -f part3/step1/get-champion-infos
		rm -f part3/step2/check-magic-champions
		rm -f part3/step3/your_binary_calling_your_function
		find . -name "*.o" -type f -delete
		@echo "Everything has been cleaned, do make for have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make for have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

unit_tests: fclean
		make all
		gcc -o unit_tests tests/*.c -I include/ \
			-L ./ -lmy -lcriterion --coverage


tests_run:
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
		make fclean

segfault:
		make libmy.a
		gcc -o $(PROJECT_NAME) -g $(SRC) $(INCL) $(LIB_COMP) $(CFLAGS)

part_one:
	make part1/step1/write-some-text
	make part1/step2/write-a-number-as-text
	make part1/step3/write-a-number-as-int
	make part1/step4/without-padding
	make part1/step5/with-padding

part1/step1/write-some-text: part1/step1/write_some_text.o
		gcc -o $@ $^

part1/step1/write_some_text.o: part1/step1/write_some_text.c
		gcc -c -o $@ $< $(CFLAGS)

part1/step2/write-a-number-as-text: part1/step2/number_as_text.o
		gcc -o $@ $^

part1/step2/number_as_text.o: part1/step2/number_as_text.c
		gcc -c -o $@ $< $(CFLAGS)

part1/step3/write-a-number-as-int: part1/step3/number_as_int.o
		gcc -o $@ $^

part1/step3/number_as_int.o: part1/step3/number_as_int.c
		gcc -c -o $@ $< $(CFLAGS)

part1/step4/without-padding: part1/step4/without_padding.o
		gcc -o $@ $^

part1/step4/without_padding.o: part1/step4/without_padding.c
		gcc -c -o $@ $< $(CFLAGS)

part1/step5/with-padding: part1/step5/with_padding.o
		gcc -o $@ $^ -I ./

part1/step5/with_padding.o: part1/step5/with_padding.c
		gcc -c -o $@ $< $(CFLAGS)

part_two:
	make part2/step1/yolotron-asm
	make part2/step2/yolotron-vm

part2/step1/yolotron-asm: $(patsubst %.c,%.o,$(wildcard part2/step1/*.c))
		gcc -o $@ $^ $(LIB_COMP) $(CFLAGS)

part2/step2/yolotron-vm: $(patsubst %.c,%.o,$(wildcard part2/step2/*.c))
		gcc -o $@ $^ $(CFLAGS)

part3/step1/get-champion-infos: $(patsubst %.c,%.o,$(wildcard part3/step1/*.c))
		gcc -o $@ $^ $(LIB_COMP) $(CFLAGS)

part3/step1/get_champions_info.o: part3/step1/get_champions_info.c
		gcc -c -o $@ $< $(CFLAGS)

part3/step2/check-magic-champions: $(patsubst %.c,%.o,$(wildcard part3/step2/*.c))
		gcc -o $@ $^ $(LIB_COMP) $(CFLAGS)
part3/step2/check_magic_champions.o: part3/step2/check_magic_champions.c
		gcc -c -o $@ $< $(CFLAGS)

part3/step3/your_binary_calling_your_function: $(patsubst %.c,%.o,$(wildcard part3/step3/*.c))
		gcc -o $@ $^ $(LIB_COMP) $(CFLAGS)
part3/step3/your_binary_calling_your_function.o: part3/step3/your_binary_calling_your_function.c
		gcc -c -o $@ $< $(CFLAGS)

part_three:
	make part3/step1/get-champion-infos
	make part3/step2/check-magic-champions
%.o: %.c
		gcc -c -o $@ $< $(CFLAGS)

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
