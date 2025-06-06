# Dev Log:

This document must be updated daily every time you finish a work session.

## Sophie Liu

### 2025-05-15 - whitespace research
- Started looking into the syntax of whitespace and how numbers work in it and typed up corresponding notes. (40 min)
- Noted down the syntax for input and output for whitespace. (10 min)

**Resources found:**
- https://en.wikipedia.org/wiki/Whitespace_(programming_language)
- http://www.youtube.com/watch?v=ea7HZ96dwqs
- https://www.youtube.com/watch?v=dIZM68voaY8
- https://www.dcode.fr/whitespace-language
- https://hackage.haskell.org/package/whitespace-0.4/src/docs/tutorial.html

### 2025-05-16 - research & stack implementation
- Using the resouces found the other day, added notes on how numbers and math operations work and the syntax for heap access. (20 min)
- Started writing basic functions for a stack. (20 min)

### 2025-05-19 - stack implementation cont.
- Wrote swap, discard, copy, and slide functions for stack & fixed some function calls in previously written functions. (35 min)
- Wrote tests for the stack functions. Fixed faulty logic in slide function and exception statements. (20 min)

### 2025-05-20 - stack implementation cont. cont.
- Wrote pop function for stack and fixed a few more bugs in the exception if statements. (20 min)
- Wrote add, subtract, divide, mulitply, and modulo functions. (20 min)
- Wrote comments for the functions, fixed incorrect logic for slide function, wrote tests. (30 min)

### 2025-05-21 - whitespace knowledge clarification
- Clarified how heap access and input/output works in whitespace using the goated [video](https://www.youtube.com/watch?v=O406bEHAOcc) Stacey found. (10 min)

### 2025-05-22 - heap implementation
- Created a heap struct and wrote store and retrieve functions for a heap. (20 min)

### 2025-05-23 - heaps & math operation fixes
- Added heap code to makefile and updated the math operation functions to push the found value to a stack and added an error to division by 0 and mod 0 cases. (40 min)
- Updated print statements when encounter an error & updated comments to reflect above changes. (15 min)
- Wrote heap tests. (20 min)
- Merged branch with main and added function calls to main program. (20 min)

### 2025-05-24 - i/o implementation
- Wrote and tested input char/num and output char/num functions. (50 min)

### 2025-05-25 - merges & heap fixes
- Added i/o files to main and added i/o function calls to main program. (15 min)
- Updated error print statements to add clarity on which IMP is causing the issue & fixed the catch if statement for the math functions to detect for < 2 items rather than < 1 & added more catch statements to the heap, stack, io, and math functions. (35 min)

### 2025-05-27 - main prog & diagrams
- Discussed with group on their thoughts on how we would ask for user input. Worked on getting a number parameter in main program to finish stack implementation in main code. (20 min)
- Drew some diagrams to help explain stack manipulation and heap access (20 min)

### 2025-05-28 - diagrams, presentation updates, & bug fixes
- Drew diagrams for i/o and math. Added diagrams to presentation markdown file, did some formatting changes to it and added some additional content explaining further some concepts. (45 min)
- Fixed a grammar issue in a comment (< 1 min)
- Fixed some bugs that prevented the interpreter from working on macs (15 min)

### 2025-05-29 - presentation updates
- Added tables on the whitespace syntax for each command & made some formatting changes to the markdown files (40 min)
- Added the print statements asking for input (3 min)

### 2025-05-30 - test cases (this took way too long)
- Wrote some test cases for arithmetic operations and inputting numbers (70 min)

### 2025-05-02 - presentation updates, bug fixes & video
- Added more references to the readme and added an explanation for the arithmetic2 test & fixed an input bug (25 min)
- Wrote a brief script for myself and recorded the final video with the others (45 min)

### 2025-05-02 - final touches
- Added 'goodbye' print statement for when user ctrl c's & added links to the references found/used to the devlog (20 min)
