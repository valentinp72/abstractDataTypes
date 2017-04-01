PROGS = binaryTree

all: $(PROGS)/test

$(PROGS)/test: $(PROGS)/test.o $(PROGS)/$(PROGS).o
	gcc -o $@ ${FLAGS} $^

%.o: %.c
	gcc -Wall -c $^ -o $@

clean:
	find . -name '*.o' -delete #remove *.o files in all directories
	rm binaryTree/test

clear: clean

