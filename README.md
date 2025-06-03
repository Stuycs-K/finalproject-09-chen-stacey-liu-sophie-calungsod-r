[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/am3xLbu5)

# Whitespace Language Interpreter

### GROUP NAME: "[&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;]"

Raechel Calungsod, Stacey Chen, Sophie Liu

### Project Description:
This project is a Whitespace interpreter. Whitespace is an esoteric programming language that was 
written by Edwin Brady and Chris Morris in 2002. Whitespace only takes in spaces, tabs, and new lines
and translates it into plaintext or executable code using a set algorithm. Our Whitespace interpreter
can do two things depending on the option used: take in a file containing Whitespace and print
out the code consisting of "[Tab]", "[Space]", or "[LF]" (for line feed, or new lines), or take
in a file containing Whitespace and run the code.

***

## Instructions:

First, cd into the interpreter directory.

```shell
cd interpreter/
```

### Here, the user will use "make whitespace" and two required flags to either run or print a file.

**Flag 1 Options (-l/-s):**
1. -l: Used if a test file is written with letters in place of spaces, tabs, and new lines. 'L' or 'N' represents a new line, 'T' represents a tab, and 'S' represents a space.
2. -s: Used if a test file is written with spaces, tabs, and new lines.

**Flag 2 Options (-p/-r):**
1. -p: Prints the tabs, spaces, and line feeds (new lines) that make up the whitespace code in a readable format.
2. -r: Runs the whitespace code written.

**All Options**
1. `make whitespace ARGS="-l -p [file name]"` -> Prints the contents of a file written with letters in a readable format.
2. `make whitespace ARGS="-l -r [file name]"` -> Runs the code from a file written with letters.
3. `make whitespace ARGS="-s -p [file name]"` -> Prints the contents of a file written with spaces in a readable format.
4. `make whitespace ARGS="-s -r [file name]"` -> Runs the code from a file written with spaces.

## For testing, users may use a number of test files included in `interpreter/tests`.
**EXAMPLE:** `make whitespace ARGS="-l -r tests/arithmetic_letters.txt"`

### Requires the -l option:
1. arithmetic_letters.txt - Returns the sum of two inputted numbers.
```shell
make whitespace ARGS="-l -r tests/arithmetic_letters.txt"
```
2. arithmetic2.txt - Adds, subtracts, multiplies, divides, and mods numbers, and outputs their ASCII equivalents to create the word Pizza.
```shell
make whitespace ARGS="-l -r tests/arithmetic2.txt"
```
3. charEcho_letters.txt - Type one character and press enter. The character will be echoed back. Use ^C to exit.
```shell
make whitespace ARGS="-l -r tests/charEcho_letters.txt"
```
4. hw_letters.txt -  Prints "Hello, World"
```shell
make whitespace ARGS="-l -r tests/hw_letters.txt"
```
5. subroutine2_letters.txt - Tests flow control subroutines, prints "-15" (the sum of the numbers pushed onto the stack) if it works correctly.
```shell
make whitespace ARGS="-l -r tests/subroutine2_letters.txt"  
```
6. truth_letters.txt - A typical truth machine used to test esoteric languages. If 0 is inputted, 0 is printed once. If any number other than 0 is inputted, 1 will be printed infinitely (use ^C to exit).
```shell
make whitespace ARGS="-l -r tests/truth_letters.txt"  
```
***

### Requires the -s option:
1. charEcho.txt - Type one character and press enter. The character will be echoed back. Use ^C to exit.
```shell
make whitespace ARGS="-s -r tests/charEcho.txt"
```
2. hw.txt - Prints "Hello, World!"
```shell
make whitespace ARGS="-s -r tests/hw.txt"
```
3. subroutine.txt - Tests flow control subroutines, prints "30" (the result after performing operations on the stack) if it works correctly.
```shell
make whitespace ARGS="-s -r tests/subroutine.txt"
```
4. testfc.txt - Tests flow control jumps and labels, prints "abc" (the letters pushed onto the stack) if it works correctly.
```shell
make whitespace ARGS="-s -r tests/testfc.txt"
```
5. testfc2.txt - Tests flow control jumps and labels, prints "ababc" (the letters pushed onto the stack) if it works correctly.
```shell
make whitespace ARGS="-s -r tests/testfc2.txt"
```
6. testfc3.txt - Tests flow control jumps and labels, prints "ababab..." indefinitely (the letters pushed onto the stack) if it works correctly.
```shell
make whitespace ARGS="-s -r tests/testfc3.txt"
```
7. truth.txt - A typical truth machine used to test esoteric languages. If 1 is inputted, 1 will be printed infinitely (use ^C to exit). If 0 is inputted, 0 is printed once.
```shell
make whitespace ARGS="-s -r tests/truth.txt"  
```

### Resources / References:

1. [Esolangs Wiki - Whitespace page](https://esolangs.org/wiki/Whitespace)
2. [Esolangs Wiki - Esoteric programming language](https://esolangs.org/wiki/Esoteric_programming_language)
3. [Esolangs Wiki - Truth machine test](https://esolangs.org/wiki/Truth-machine)
4. [Wikipedia - Whitespace (programming language)](https://en.wikipedia.org/wiki/Whitespace_(programming_language))
5. [Whitespace decoder from dcode](https://www.dcode.fr/whitespace-language)
6. [Whitespace tutorial from Hackage](https://hackage.haskell.org/package/whitespace-0.4/src/docs/tutorial.html)
7. [Whitespace | Esolang Showcase by The Zip Creator (video)](https://www.youtube.com/watch?v=O406bEHAOcc)
8. [Whitespace Programming Language Tutorial by Script Kiddie (video)](https://www.youtube.com/watch?v=ea7HZ96dwqs)
9. [ Whitespace! by Truttle1 (video)](https://www.youtube.com/watch?v=dIZM68voaY8)
