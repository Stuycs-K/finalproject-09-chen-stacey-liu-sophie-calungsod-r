.PHONY: whitespace

whitespace: whitespace.o
	@gcc -o whitespace whitespace.o
	@./whitespace $(ARGS)

whitespace.o: whitespace.c whitespace.h
	@gcc -c whitespace.c
	
clean:
	@rm *.o
	@rm whitespace
	@rm -f