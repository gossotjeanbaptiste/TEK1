# Epi-Cuddle - A Reimplementation of Python's pandas in C

## 🛠️ Compilation Instructions

#### To compile the lib/my library:

***make***

#### If you get the message: Nothing to be done for 'all', try:

***make re***

#### To clean only lib/my:

***make clean***

#### To clean all generated files throughout the project:

***make fclean***

## 🎯 Coding Style

To check the coding style (Epitech standard):

***make cs***

## 🧬 Manual Test Compilation & Execution

You can manually compile and run individual test files for specific features:

### Custom Separator Test
```shell
cd /home/hokai/delivery/G-AIA-200-NCY-2-1-cuddle-jean-baptiste.gossot
gcc -Wall -Wextra -o test_custom_separator tests/test_custom_separator.c -L. -lcuddle -lm
./test_custom_separator
./test_mean_calculation
```
### Mean Calculation Test

```shell
cd /home/hokai/delivery/G-AIA-200-NCY-2-1-cuddle-jean-baptiste.gossot
gcc -Wall -Wextra -o test_mean_calculation tests/test_mean_calculation.c -L. -lcuddle -lm
./test_mean_calculation
```
### Memory Management Test
```shell
cd /home/hokai/delivery/G-AIA-200-NCY-2-1-cuddle-jean-baptiste.gossot
gcc -Wall -Wextra -o test_memory_management tests/test_memory_management.c -L. -lcuddle -lm
./test_memory_management
```
### Separators Handling Test
```shell
cd /home/hokai/delivery/G-AIA-200-NCY-2-1-cuddle-jean-baptiste.gossot
gcc -Wall -Wextra -o test_separators tests/test_separators.c -L. -lcuddle -lm
./test_separators
```
## 🧸 Project Overview

Epi-Cuddle is a C-based static library called `libcuddle.a` that reimplements core features of the Python `pandas` library. It is designed to manipulate tabular data from CSV files, including reading, writing, transforming, filtering, sorting, and aggregating datasets.

The goal is to build a flexible and efficient system that mimics key pandas operations while handling various data types (strings, ints, floats, booleans). The library provides an interface for data analysis in C.

## 👤 Author

Jean-Baptiste Gossot  
Pierre-Alexandre Guerin
