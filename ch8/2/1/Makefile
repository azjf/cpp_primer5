CPP = /usr/bin/g++

all: a.out
	./a.out ifile1 ifile2

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall

clean:
	rm a.out

run: a.out
	./a.out
