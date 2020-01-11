VARIABLE = gcc -Wall -g
CLEAN = *.o *.a *.so

all: trie run

trie:
	$(VARIABLE) -o ‫‪frequency‬‬.o ‫‪frequency‬‬.c

run:
	./‫‪frequency‬‬.o

clean:
	rm -f $(CLEAN)



