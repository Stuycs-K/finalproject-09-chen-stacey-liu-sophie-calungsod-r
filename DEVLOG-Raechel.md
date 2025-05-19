# Dev Log:

This document must be updated daily every time you finish a work session.

## Raechel Calungsod

### 2025-05-15 - Setting up C files
I spent 35 minutes in class setting up whitespace.c and whitespace.h,
which will serve as the basis of our Whitespace interpreter. I set up
a function to parse args to run a command with execvp and began a
function that will read the file containing Whitespace text. The .h
file includes all required libraries and new functions.

At home, I spent 30 minutes reviewing the syntax and rules of Whitespace
and old C files in order to finish up the function used to read the 
Whitespace files. It should now correctly return the tabs, spaces, and new
lines in a string, but I will have to test properly tomorrow.

### 2024-05-16 - Whitespace spreadsheet formatting, fixing main C code, and linked lists
I spent 40 minutes of class time creating a spreadsheet that contains 
the functions of each Whitespace command and how to call each. This will
help us with organization when writing out our code. I also changed some of
the main C code after some minimal testing and checking in with group mates.

At home, I spent 30 minutes continuing to organize our spreadsheet and started
to figure out a linked list structure for the Whitespace input. I created a
new struct and started a function that will parse a string holding the file
contents into a linked list of the new struct nodes.
