CPP = /usr/bin/g++

all: a.out
	./a.out infile

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
