# Whitespace Interpreter

**What is an esoteric language?**:

An esoteric programming language is an experimental programming language written for reasons other than its practicality. Often, esoteric languages (or esolangs) are written to test a programmer's capabilities, to play with new ideas, to try obfuscation (making it as hard to read as possible), or even as a joke.

**What is Whitespace?**:

***Whitespace*** is an esoteric language written by Edwin Brady and Chris Morris in 2003. In a strange diversion from typical programming, Whitespace coding only uses spaces, tabs, and new lines -- all other characters are completely ignored. For our project, we coded an interpreter that can do two things:

1) Translate Whitespace to plain text and print out the result
2) Translate a command written in Whitespace and execute it directly

Our interpreter runs with one command in the terminal: make whitespace. The options added determine the result:

Printing the Whitespace from a file in plain text: <br>
`make whitespace ARGS="-s -p [FILE NAME]"` <br><br>
Executing the Whitespace code from a file: <br>
`make whitespace ARGS="-s -r [FILE NAME]"`

The '-s' reads files written with spaces, tabs, and new lines, but can be replaced with a '-l', which reads files written with letters 'S', 'T', and 'N' or 'L' to represent the spaces.

***

Once we reviewed a few color-coded examples of Whitespace code, we dove into understanding Instruction Modification Parameters, or IMP. IMP is not a commonly used term, but it is used in documentation written for Whitespace (although official, original documentation has been unpublished since its creation). IMP refers to the beginning of a command, used to designate its purpose when interpreting code. For Whitespace, there are five different IMPs for five different categories of commands:

1. Stack manipulation
2. Arithmetic
3. Heap access
4. Flow control
5. Input/output (I/O)


### Numbers
- Works through binary: space represents 0, tab represents 1
- A linefeed signals the end of a number
- Space in front → number is positive
- Tab in front → number is negative

Example: <br>
- [SPACE]**[TAB][SPACE][SPACE][TAB][SPACE][TAB][TAB][LINEFEED]** (S**TSSTSTTL**) → +**1001011** → 75 <br>
- [TAB]**[TAB][TAB][SPACE][SPACE][TAB][SPACE][LINEFEED**] (T**TTSSTSL**) → -**110010** → -50


## Stack Manipulation

For stack manipulation, the IMP at the beginning of each command is just a [SPACE]. Stack manipulation commands are used to modify the stack---pushing items, duplicating items, swapping items, discarding items, etc.

Operator | Parameter | Command
--- | --- | ---
[SPACE] | number | **push**
[LF][SPACE] |  | **duplicate**
[LF][LF] |  | **discard**
[LF][TAB] | | **swap**
[TAB][SPACE] | number | **copy**
[TAB][LF] | number | **slide**

\* *pop is not a command that can be called by the user, but it is used in other commands*

<img src="diagrams/stack.jpg" alt="stack diagram" width="400"/>

## Arithmetic

For arithmetic, the IMP at the beginning of each command is [TAB][SPACE]. Whitespace handles simple arithmetic, including addition, subtraction, multiplication, integer division, and modulo. The numbers used for these commands come from the stack in the order *second value popped* [operation] *first value popped*.

Operator | Parameter | Command
--- | --- | ---
[SPACE][SPACE] |  | **additon**
[SPACE][TAB] |  | **subtraction**
[SPACE][LF] |  | **multiplication**
[TAB][SPACE] |  | **division**
[TAB][TAB] |  | **modulo**

<img src="diagrams/arithmetic-division.jpg" alt="arithmetic diagram" width="400"/>

## Heap Access

For heap access, the IMP at the beginning of each command is [TAB][TAB]. There are only two commands for heaps: storing a value in a heap and retrieving a value from a heap. When storing a value in the heap, the value and address is popped from the stack. When retrieving a value from the heap, an address is popped from the stack and the corresponding value from the heap is pushed to the stack.

Operator | Parameter | Command
--- | --- | ---
[SPACE] |  | **store**
[TAB] |  | **retrieve**

<img src="diagrams/heap.jpg" alt="heap diagram" width="400"/>

## Input/Output

Finally, for input/output, the IMP at the beginning of each command is [TAB][LINEFEED]. Input/output commands pop a value from a stack and performs an action with it, whether it be using it as an address for a user inputted value or as the value to be outputted.

Operator | Parameter | Command
--- | --- | ---
[TAB][SPACE] |  | **input ascii character**
[TAB][TAB] |  | **input number**
[SPACE][SPACE] |  | **output ascii character**
[SPACE][TAB] |  | **output number**

<img src="diagrams/io.jpg" alt="i/o diagram" width="400"/>

**Heap access, stack, i/o and arithmetic test:** <br>
ex. arithmetic_letters.txt - Returns the sum of two inputted numbers.
```shell
make whitespace ARGS="-l -r tests/arithmetic_letters.txt"
```

charEcho.txt - Type one character and press enter. The character will be echoed back. Use ^C to exit.
```shell
make whitespace ARGS="-s -r tests/charEcho.txt"
```

## Flow Control

For flow control, the IMP at the beginning of each command is [LINEFEED]. Flow control, essentially, determines how the program moves from one statement to another, based on given conditions. This involves handling things like loops and conditional statements. Some flow control operations take a label, which, similar to a number, is a sequence of tabs and spaces terminated by a linefeed. With this label, we can mark down certain locations in the program to “jump” to when the label is called. Calling a subroutine is similar to jumping to a label, except that subroutines are terminated by a return statement.

Operator | Parameter | Command
--- | --- | ---
[SPACE][SPACE] | label | **mark a location in program**
[SPACE][TAB] | label | **call a subroutine**
[SPACE][LF] | label | **jump unconditionally to a label**
[TAB][SPACE] | label | **jump to a label if the top of the stack is zero**
[TAB][TAB] | label | **jump to label if the top of stack is negative**
[TAB][LF] |  | **end subroutine & transfer control back to caller**
[LF][LF] |  | **end program**

ex. testfc3.txt - Tests flow control jumps and labels, prints "ababab..." indefinitely (the letters pushed onto the stack) if it works correctly.
```shell
make whitespace ARGS="-s -r tests/testfc3.txt"
```

ex. truth.txt - A typical truth machine used to test esoteric languages. If 0 is inputted, 0 is printed once. If any number other than 0 is inputted, 1 will be printed infinitely (use ^C to exit).
```shell
make whitespace ARGS="-s -r tests/truth.txt"  
```

<br>
