##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

MAKEFLAGS += --no-print-directory

S1 = Semester_1

S1_CPE = $(S1)/G1-Elementary-Prog-in-C
BSQ = $(S1_CPE)/Project-Setting_Up
ORG = $(S1_CPE)/Project-Organized
SEC = $(S1_CPE)/Project-Secured

S1_PSU = $(S1)/G1-Unix-and-Sys-Prog
MY_TOP = $(S1_PSU)/Project-my_top
MY_SUDO = $(S1_PSU)/Project-my_sudo

S1_MUL = $(S1)/G1-C-Graphical-Prog
MY_HUNTER = $(S1_MUL)/Project-my_hunter
MY_RADAR = $(S1_MUL)/Project-my_radar

S2 = Semester_2

S2_CPE = $(S2)/G2-Elementary-Prog-in-C
RFA = $(S2_CPE)/Project-Robot_Factory
AMZ = $(S2_CPE)/Project-Amazed
COR = $(S2_CPE)/Corewar

S2_ING = $(S2)/G2-Software_Engineering
MYW = $(S2_ING)/My_World
WOL = $(S2_ING)/Wolf3D

CUD = $(S2)/G2-Discovery_of_Data_Analysis/Project-Cuddle

all: compile

compile:
		@echo "===Compiling Semester 1 Project==="
		@cd $(BSQ) && make && echo "Compiled Setting_Up"
		@cd $(ORG) && make && echo "Compiled Organized"
		@cd $(SEC) && make && echo "Compiled libhashtable.a (Secured)"
		@cd $(MY_TOP) && make && echo "Compiled my_top"
		@cd $(MY_SUDO) && make && echo "Compiled my_sudo"
		@cd $(MY_HUNTER) && make && echo "Compiled my_hunter"
		@cd $(MY_RADAR) && make && echo "Compiled my_radar"
		@echo "===Compiled all project of S1 with Makefile==="
		@echo "===Compiling Semester 2 Project==="
		@cd $(RFA) && make && echo "Compiled Robot_Factory"
		@cd $(AMZ) && make && echo "Compiled Amazed"
		@cd $(COR) && make && echo "Compiled Corewar"
		@cd $(MYW) && make && echo "Compiled My_World"
		@cd $(WOL) && make && echo "Compiled Wolf3D"
		@cd $(CUD) && make && echo "Compiled libcuddle.a (Cuddle)"
		@echo "===Compiled all project of S2 with Makefile==="
		@echo "You can find all the binary in their respective directory"

clean:
		@echo "===Cleaning Semester 1 Project==="
		@cd $(BSQ) && make clean && echo "Cleaned Setting_Up"
		@cd $(ORG) && make clean && echo "Cleaned Organized"
		@cd $(SEC) && make clean && echo "Cleaned Secured"
		@cd $(MY_TOP) && make clean && echo "Cleaned my_top"
		@cd $(MY_SUDO) && make clean && echo "Cleaned my_sudo"
		@cd $(MY_HUNTER) && make clean && echo "Cleaned my_hunter"
		@cd $(MY_RADAR) && make clean && echo "Cleaned my_radar"
		@echo "===Cleaning Semester 2 Project==="
		@cd $(RFA) && make clean && echo "Cleaned Robot_Factory"
		@cd $(AMZ) && make clean && echo "Cleaned Amazed"
		@cd $(COR) && make clean && echo "Cleaned Corewar"
		@cd $(MYW) && make clean && echo "Cleaned My_World"
		@cd $(WOL) && make clean && echo "Cleaned Wolf3D"
		@cd $(CUD) && make clean && echo "Cleaned Cuddle"
		@echo "===All Objects Files Cleaned==="

fclean: clean
		@echo "===Cleaning Semester 1 Project Binaries==="
		@cd $(BSQ) && make fclean && echo "Cleaned Setting_Up"
		@cd $(ORG) && make fclean && echo "Cleaned Organized"
		@cd $(SEC) && make fclean && echo "Cleaned Secured"
		@cd $(MY_TOP) && make fclean && echo "Cleaned my_top"
		@cd $(MY_SUDO) && make fclean && echo "Cleaned my_sudo"
		@cd $(MY_HUNTER) && make fclean && echo "Cleaned my_hunter"
		@cd $(MY_RADAR) && make fclean && echo "Cleaned my_radar"
		@echo "===Cleaning Semester 2 Project Binaries==="
		@cd $(RFA) && make fclean && echo "Cleaned Robot_Factory"
		@cd $(AMZ) && make fclean && echo "Cleaned Amazed"
		@cd $(COR) && make fclean && echo "Cleaned Corewar"
		@cd $(MYW) && make fclean && echo "Cleaned My_World"
		@cd $(WOL) && make fclean && echo "Cleaned Wolf3D"
		@cd $(CUD) && make fclean && echo "Cleaned Cuddle"
		@echo "===All Binaries + Unwanted Files Cleaned==="

re: fclean all

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make for have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

.PHONY: all compile clean fclean re cs