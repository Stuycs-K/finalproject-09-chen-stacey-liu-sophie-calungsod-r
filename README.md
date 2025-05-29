[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/am3xLbu5)

# Whitespace Language Interpreter
 
### GROUP NAME: "[&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;]"

Raechel Calungsod, Stacey Chen, Sophie Liu
       
### Project Description:
This project is a Whitespace interpreter. Whitespace, an esoteric programming language written 
by Edwin Brady and Chris Morris in 2002. Whitespace only takes in spaces, tabs, and new lines
that can be translated back into plaintext using a set algorithm. Our Whitespace interpreter
can do two things depending on the option used: take in a file containing Whitespace and print 
out the code consisting of "[Tab]", "[Space]", or "[LF]" (for line feed, or new lines), or take 
in a file containing Whitespace and run the code.
  
### Instructions:

How does the user install/compile/run the program. (CHANGE THIS!!!!!)

In order to compile and run the program, the user can use one of two commands:
1. make whitespace ARGS="-p [file name]"
2. make whitespace ARGS="-r [file name]"

In both commands, the file should contain properly written whitespace code. The -p option will print the tabs, spaces, and line feeds (new lines) that make up the whitespace code, while the -r option will run the code written.

For testing, users may use a number of test files included in our interpreter directory:
1. hw.txt - Prints "Hello, World!"
2. truth.txt - A typical truth machine used to test esoteric languages. If 1 is inputted, 1 will be printed infinitely (use ^C to exit). If 0 is inputted, 0 is printed once. 
3. charEcho.txt - Type one character and press enter. The character will be echoed back. Use ^C to exit.

### Resources/ References:

1. [Esolangs Wiki - Whitespace page](https://esolangs.org/wiki/Whitespace)
2. [Esolangs Wiki - Esoteric programming language](https://esolangs.org/wiki/Esoteric_programming_language)
3. [Esolangs Wiki - Truth machine test](https://esolangs.org/wiki/Truth-machine)
4. [Whitespace decoder from dcode](https://www.dcode.fr/whitespace-language)
5. [Whitespace tutorial from Hackage](https://hackage.haskell.org/package/whitespace-0.4/src/docs/tutorial.html)
6. [Whitespace | Esolang Showcase by The Zip Creator (video)](https://www.youtube.com/watch?v=O406bEHAOcc)
