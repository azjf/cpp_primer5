CPP = /usr/bin/g++

all: a.out
	./a.out -d -o ofile data0

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
