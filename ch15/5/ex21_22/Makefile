CPP = /usr/bin/g++

all: a.out
	./a.out

a.out: *.cpp
	$(CPP) $^ -lm -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
