.PHONY: whitespace

whitespace: whitespace.o stack.o heap.o math.o io.o
	@gcc -o whitespace whitespace.o stack.o heap.o math.o io.o
	@./whitespace $(ARGS)

whitespace.o: whitespace.c whitespace.h stack.h heap.h math.h io.h
	@gcc -c whitespace.c

stack.o: stack.c
	@gcc -c stack.c

heap.o: heap.c stack.h
	@gcc -c heap.c

math.o: math.c stack.h
	@gcc -c math.c

<<<<<<< HEAD
io.o: io.c stack.h heap.h
	@gcc -c io.c
=======
numbertest.o: numbertest.c numbertest.h
	@gcc -c numbertest.c

flowcontrol.o: flowcontrol.c stack.h
	@gcc -c flowcontrol.c
>>>>>>> stacey

clean:
	@rm *.o
	@rm whitespace
	@rm -f
