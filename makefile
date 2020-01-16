VARIABLE = gcc -Wall -g
CLEAN = *.o *.a *.so

all: main.o trie.o frequency

frequency: trie.o main.o
		$(VARIABLE) -fPIC -o frequency trie.o main.o -lm
		
trie.o: trie.c trie.h
		$(VARIABLE) -fPIC -c trie.c

main.o: main.c trie.c trie.h
		$(VARIABLE) -c main.c

.PHONY:	clean all

clean:
	rm -f $(CLEAN)









