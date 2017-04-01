PROGS = labels/test binaryTree/test 

all: $(PROGS)

labels/test: labels/test.o labels/labels.o
	gcc -o $@ $^
binaryTree/test: binaryTree/test.o binaryTree/binaryTree.o labels/labels.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $^ -o $@

clean:
	find . -name '*.o' -delete #remove *.o files in all directories
	rm $(PROGS)

clear: clean

