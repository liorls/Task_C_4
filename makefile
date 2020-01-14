VARIABLE = gcc -Wall -g
CLEAN = *.o *.a *.so

all: main run

main:
	$(VARIABLE) -o ‫‪frequency‬‬ ‫‪frequency‬‬.c

run:
	./‫‪frequency‬‬

.PHONY: clean all 

clean:
	rm -f $(CLEAN)



