.PHONY: whitespace

whitespace: whitespace.o stack.o heap.o math.o
	@gcc -o whitespace whitespace.o stack.o heap.o math.o
	@./whitespace $(ARGS)

whitespace.o: whitespace.c whitespace.h stack.h heap.h math.h
	@gcc -c whitespace.c

stack.o: stack.c
	@gcc -c stack.c

heap.o: heap.c stack.h
	@gcc -c heap.c

math.o: math.c stack.h
	@gcc -c math.c

clean:
	@rm *.o
	@rm whitespace
	@rm -f
