# Whitespace Interpreter

*What is an esoteric language?*:
An esoteric language is...

***Whitespace*** is an esoteric language written by Edwin Brady and Chris Morris in 2003. In a strange diversion from typical programming, Whitespace coding only uses spaces, tabs, and new lines -- all other characters are completely ignored. For our project, we coded an interpreter that can do two things:

1) Translate Whitespace to plain text and print out the result
2) Translate a command written in Whitespace and execute it directly

In order for this to work, we first needed to understand how Whitespace functions. There are three important values that Whitespace uses

- ASCII value 32 represents a space
- ASCII value 9 represents a tab
- ASCII value 10 represents *line feed*, or a new line.

Our interpreter is ran with one command in the terminal: make whitespace. The option added determines the outcome:

Printing the whitespace in plain text:
>make whitespace ARGS="-p'

Executing the whitespace command:
>make whitespace ARGS="-r' // i dont remember ???????

Once we reviewed a few color-coded examples of Whitespace code, we dove into understanding Instruction Modification Parameters, or IMP. IMP is not a commonly used term, but it is used in documentation written for Whitespace (although official, original documentation has been unpublished since its creation). IMP refers to the beginning of a command, used to designate its purpose when interpreting code. For Whitespace, there are five different IMPs for five different categories of commands: Input/Output, stack manipulation, arithmetic, flow control, and heap access.

--> explain what our stack system is and how it works here

For input/output, the IMP at the beginning of each command is [TAB][LINEFEED]. Input/output commands generally pop values from a stack, perform an action on it, and outputs it or stores it to be used for later.

[show examples and explain the commands specifically]

For stack manipulation, the IMP at the beginning of each command is just a [SPACE]. Stack manipulation commands are used to modify the stack---pushing items, duplicating items, swapping items, discarding items, etc.

[show examples and explain the commands specifically]


For arithmetic, the IMP at the beginning of each command is [TAB][SPACE]. Whitespace handles simple arithmetic, including addition, subtraction, multiplication, integer division, and modulo. The numbers used for these commands come from the stack in the order *first value popped* + operation + *second value popped*.

[show examples and explain the commands specifically]

For flow control, the IMP at the beginning of each command is [LINEFEED]. Flow control, essentially, is regulating data flow in order to prevent overwhelming the receiver (what is the receiver?? regulate how??). Somebody explain this......

[show examples and explain the commands specifically]


Finally, for heap access, the IMP at the beginning of each command is a [TAB][TAB]. There are only two commands for heap control: storing a value in heap and retrieving a value from heap. (should this be moved to the beginning??? im not sure)

[show examples and explain the commands specifically]



- how numbers work... should that be moved up as well
