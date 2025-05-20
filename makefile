compile runme: tests.o stack_test.o math_test.o
	@gcc -o runme tests.o stack_test.o math_test.o

tests.o: tests.c stack_test.h math_test.h
	@gcc -c tests.c

stack_test.o: stack_test.c
	@gcc -c stack_test.c

math_test.o: math_test.c stack_test.h
	@gcc -c math_test.c

run: runme
	@./runme

clean:
	@rm *.o
	@rm runme
