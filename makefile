compile runme: tests.o stack_test.o heap_test.o math_test.o io_test.o
	@gcc -o runme tests.o stack_test.o heap_test.o math_test.o io_test.o

tests.o: tests.c stack_test.h math_test.h heap_test.h io_test.h
	@gcc -c tests.c

stack_test.o: stack_test.c
	@gcc -c stack_test.c

heap_test.o: heap_test.c stack_test.h
	@gcc -c heap_test.c

math_test.o: math_test.c stack_test.h
	@gcc -c math_test.c

io_test.o: io_test.c stack_test.h heap_test.h
	@gcc -c io_test.c

run: runme
	@./runme

clean:
	@rm *.o
	@rm runme
