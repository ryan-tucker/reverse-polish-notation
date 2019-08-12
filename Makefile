rpn: rpn.o input.o stack.o
	gcc -o rpn rpn.o input.o stack.o

rpn.o: rpn.c input.h stack.h
	gcc -c rpn.c

input.o: input.c input.h
	gcc -c input.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm input.o rpn.o stack.o rpn
