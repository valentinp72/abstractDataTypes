all: test

test: test.o binaryTree.o
	gcc -o $@ ${FLAGS} $^

test.o: test.c binaryTree.h
	gcc -c $<
binaryTree.o: binaryTree.c
	gcc -c $<

clean:
	rm *.o
	rm test

clear: clean

