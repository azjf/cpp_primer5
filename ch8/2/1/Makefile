CPP = /usr/bin/g++

all: a.out
	./a.out ifile1 ifile2

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
