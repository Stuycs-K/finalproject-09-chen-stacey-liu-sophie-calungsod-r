PRESENTATION.md : Create your presentation/lesson "slides". This should include all of the info from your presentation. You SHOULD NOT just read the slides, but the slides should contain enough information such that if you didn't watch the video, you would learn most of it.


Whitespace is an esoteric language written by Edwin Brady and Chris morris in 2003. In a strange diversion from typical programming, Whitespace coding only uses spaces, tabs, and new lines -- all other characters are completely ignored.

There are three important ASCII values used in our code: 32 for space, 9 for tab, and 10 for *line feed*, or a new line. 

The first thing that our group had to learn about is Instruction Modification Parameters, or IMP. IMP refers to the beginning of a command, used to designate its purpose when interpreting code. For Whitespace, there are five different IMPs for five different categories of commands: Input/Output, stack manipulation, arithmetic, flow control, and heap access.

--> explain what our stack system is and how it works here

For input/output, the IMP at the beginning of each command is [TAB][SPACE]. Input/output commands generally pop values from a stack, perform an action on it, and outputs it or stores it to be used for later.

[show examples and explain the commands specifically]

For stack manipulation, the IMP at the beginning of each command is just a [SPACE]. Stack manipulation commands are used to modify the stack---pushing items, duplicating items, swapping items, discarding items, etc.

[show examples and explain the commands specifically]




Rules:

Stack Manipulation				
Push a number onto stack	[SPACE]	[SPACE]	[NUMBER]	
Duplicate top item on stack	[SPACE]	[LINEFEED]	[SPACE]	
Swap the top 2 items on stack	[SPACE]	[LINEFEED]	[TAB]	
Discard top item on stack	[SPACE]	[LINEFEED]	[LINEFEED]	
Copy nth item on the stack onto top of stack	[SPACE]	[SPACE]	[NUMBER]	
Slide n items off the stack, keeping top item	[SPACE]	[LINEFEED]	[NUMBER]	
				
MATH	1st value popped [operation] 2nd value popped			
Addition	[TAB]	[SPACE]	[SPACE]	[SPACE]
Subtraction	[TAB]	[SPACE]	[SPACE]	[TAB]
Multiplication	[TAB]	[SPACE]	[SPACE]	[LINEFEED]
(Integer) Division	[TAB]	[SPACE]	[TAB]	[SPACE]
Modulo	[TAB]	[SPACE]	[TAB]	[TAB]
				
Heap Access				
Store in heap	[TAB]	[TAB]	[SPACE]	
Retrieve from heap	[TAB]	[TAB]	[TAB]	
				
Input/Output				
Pop heap address from stack, read character as ASCII, store character to the heap address	[TAB]	[LINEFEED]	[TAB]	[SPACE]
Pop heap address from stack, read number as ASCII, store number to the heap address	[TAB]	[LINEFEED]	[TAB]	[TAB]
Pop number from stack, output as an ASCII char	[TAB]	[LINEFEED]	[SPACE]	[SPACE]
Pop number from stack, output number 	[TAB]	[LINEFEED]	[SPACE]	[TAB]
				
Flow control (regulate data flow to prevent overwhelming the receiver)				
Mark a location in program	[LINEFEED]	[SPACE]	[SPACE]	[LABEL] ????
Call a subroutine	[LINEFEED]	[SPACE]	[TAB]	[LABEL] ????
Jump unconditionally to a label	[LINEFEED]	[SPACE]	[LINEFEED]	[LABEL] ????
Jump to a label if the top of the stack is zero	[LINEFEED]	[TAB]	[SPACE]	[LABEL] ????
Jump to label if the top of the stack is negative	[LINEFEED]	[TAB]	[TAB]	[LABEL] ????
End subroutine & transfer control back to caller  	[LINEFEED]	[TAB]	[LINEFEED]	
End program	[LINEFEED]	[LINEFEED]	[LINEFEED]	
