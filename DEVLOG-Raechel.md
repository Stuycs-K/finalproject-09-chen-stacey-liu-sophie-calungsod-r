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

### 2025-05-16 - Whitespace spreadsheet formatting, fixing main C code, and linked lists
I spent 40 minutes of class time creating a spreadsheet that contains 
the functions of each Whitespace command and how to call each. This will
help us with organization when writing out our code. I also changed some of
the main C code after some minimal testing and checking in with group mates.

At home, I spent 30 minutes continuing to organize our spreadsheet and started
to figure out a linked list structure for the Whitespace input. I created a
new struct and started a function that will parse a string holding the file
contents into a linked list of the new struct nodes.


### 2025-05-19 - Combining and testing code
I spent 25 minutes in class trying to consolidate me and Stacey's code in order to
make the main program correctly interpret numbers from Whitespace. I ran into 
a segmentation fault during testing and will try to remedy this as soon as possible.
I also spent 10 minutes researching and coming up with content for our readme file.

I spent 30 minutes at home fixing errors in the code, including the segmentation 
fault that occurred while I tried to test the Whitespace number translator. After
editing the code, numbers seem to be correctly interpreted, but further testing
is needed to make sure this works within other pieces of code.

### 2025-05-20 - Writing main code
I spent 40 minutes in class testing more of our number interpretations and writing 
code for our main whitespace.c file. I focused mainly on the conditionals that determine
whether a stack manipulation, mathematical, or input/output function needs to be called
to interpret the encoded Whitespace.

I spent 25 minutes at home continuing with the function that will call which 
interpretation function to use using conditionals, this time working on flow
control and heap access. I also reorganized some of our research on my spreadsheet.

### 2025-05-22 - Writing README, presentation, and consolidating code
I spent 35 minutes in class combining code, specifically adding the basics for our
future stack control code into the main code file. I also spent time looking through
resources, editing the markdown in our README, and adding to our presentation file.

### 2025-05-23 - Writing presentation
I spent 35 minutes in class writing the beginning of our presentation markdown file
with the information that our group gathered on our shared Google Doc. Our group also
spent time reviewing each other's code, debugging, and ensuring that we're on the same page.

I spent 40 minutes at home continuing our presentation and reviewing our code. Our presentation
is mostly complete (missing examples from our actual code).

### 2025-05-23 - Fixing main code and consolidation
I spent 40 minutes in class attempting to fix some of our Whitespace code because of
inconsistencies between stack manipulation and the main file code. I also spoke to
group members to try and help with errors and decide what to write for the presentation.
