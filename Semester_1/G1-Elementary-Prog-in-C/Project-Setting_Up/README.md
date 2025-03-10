# Setting-up

You must find the largest possible square on a board while avoiding obstacles.
The board can be obtained two ways. The first one is by reading a file passed as the program’s
argument.
The file is valid if it is respecting those constraints:
- its first line contains the number of lines on the board (and only that),
- ‘.’ (representing an empty place) and ‘o’ (representing an obstacle) are the only two characters for the other lines,
- all of the lines are of the same length (except the first one),
- it contains at least one line,
- each line is terminated by ‘\n’.
You program must print the board, with some “.” replaced by “x” to represent the largest square
you found.
If ever there are several solutions, you have to represent only the highest square. If they are
still several solutions, choose the square to the left.


---

# Epi-Template-C

Before doing anything you have to do ```make start``` to modified the name of gitignore.txt to .gitignore to avoid any problem with git and make gitignore work fine.

For compilation of lib/my make : ```make``` if you can't because it say "Nothing to be done for `all'" make : ```make re``` it should recompile as expected.

For clean make : ```make clean``` to clean the lib/my and for everywhere make : ```make fclean```

For coding-style : ```make cs``` Warning : You have to recompile the lib/my before any knew compilation of your project

For unit_tests (create and run them) make : ```make unit_tests & make tests_run```