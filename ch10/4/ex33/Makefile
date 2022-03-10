CPP = /usr/bin/g++

all: a.out
	./a.out infile out_odd out_even

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
