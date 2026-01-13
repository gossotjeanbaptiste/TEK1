# Organized

Objectives
You need to be able to store and sort all the materials you have at your fingertips.
Your laboratory is really upside down and you need to organize it. This project can be divided
into 2 parts:
- Storing and handling hardware
- Sorting your stuff according to tags

In fact, there’s a third challenge! You’re going to be handling a lot of hardware and your sorting
algorithm needs to be able to process a large quantity of hardware quickly and efficiently.

---

# Epi-Template-C

Before doing anything you have to do ```make start``` to modified the name of gitignore.txt to .gitignore to avoid any problem with git and make gitignore work fine.

For compilation of lib/my make : ```make``` if you can't because it say "Nothing to be done for `all'" make : ```make re``` it should recompile as expected.

For clean make : ```make clean``` to clean the lib/my and for everywhere make : ```make fclean```

For coding-style : ```make cs``` Warning : You have to recompile the lib/my before any knew compilation of your project

For unit_tests (create and run them) make : ```make unit_tests & make tests_run```