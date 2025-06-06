# Dev Log:
## Stacey Chen
### 2025-05-15 - Whitespace Research
- Spent a full class period on researching Whitespace syntax and figuring out how numbers and stack manipulation works in Whitespace.
- Spent 30 minutes at home continuing with stack manipulation research and flow control, along with initial brainstorming of how to structure code.

Links used:
- https://esolangs.org/wiki/Whitespace
- https://www.dcode.fr/whitespace-language

### 2025-05-16 - Started coding number
- Spent a full class period figuring out how to identify numbers in Whitespace (continued with previous sources and also [this website](https://hackage.haskell.org/package/whitespace-0.4/src/docs/tutorial.html )).

### 2025-05-18 - Finished coding number
- Spent 30 minutes finishing the code for finding numbers in Whitespace.

### 2025-05-19 - Heap research & start of flow control functions
- Spent class period watching [this video](https://www.youtube.com/watch?v=O406bEHAOcc) and taking notes, specifically on heaps.
- Spent 20 minutes at home starting to write the functions for flow control.

### 2025-05-20 - Worked on flow control functions
- Spent class period working on the functions for flow control, specifically markLoc() and unCondJump().
- Spent 10 minutes at home continuing the unCondJump() functions and spent 20 minutes starting to write the conditional statements for each.

### 2025-05-22 - Worked on flow control conditional statements
- Spent 30 minutes at home on unCondJump(), findLabel(), and reordered code to integrate zeroJump() and negJump() into main code.

### 2025-05-23 - Worked on finding code examples in Whitespace that used flow control, added function for printing
- Spent class period researching examples using flow control to gain better understanding of how flow control works in whitespace
- Added a function for printing whitespace in readable text(N, S, T)

### 2025-05-25 - Cleaned up code comments and debugged flowcontrol.c
- Spent ~2.5 hours cleaning up code comments, debugging errors (mostly related to using pointer incorrectly), and testing
- Modified program to use structs to store label information
- Added function to print label_ary

### 2025-05-26 - Completed subroutine part for flow control
- Spent 10 minutes figuring out the subroutine component for flow control
- Spent ~1 hour integrating flow control code with main code and wrote a retrieveLabels() function to extract labels from the Whitespace code

### 2025-05-27 - Discussed code with partners and wrote test files
- Spent class period discussing functions with group to figure out how to implement main code and started writing Whitespace test cases
- Spent 50 minutes working on making the main code run properly, especially the areas that required reading numbers

### 2025-05-28 - Started brainstorming more test cases
- Spent class period coming up with more test cases for flow control
- Spent 30 minutes at home coming up with more test cases and debugging unCondJump()

### 2025-05-29 - Edited jump functions to handle empty stack and freed memory
- Spent 10 minutes editing jump functions to handle empty Stack
- Spent 10 minutes freeing memory
- Spent 10 minutes thinking of more test cases

### 2025-05-30 - Wrote test cases for subroutine
- Spent class period writing test cases for subroutine and making sure it works as expected

### 2025-06-01 - Debugged subroutine and added test cases
- Spent 30 minutes debugging subroutine and added some test cases (letter versions)

### 2025-06-02 - Edited test cases and worked on presentation
- Spent class period fixing/adding new test cases and worked on the explanation for flow control in PRESENTATION.md
- Spent 30 minutes and preparing for and recording the presentation video with the others

### 2025-06-03 - Cleaned up documentation and final testing
- Spent 20 minutes in class cleaning up documentation and doing final testing
