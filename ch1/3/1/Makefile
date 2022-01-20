CPP = /usr/bin/g++

all: a.out
	./a.out

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall

clean:
	rm a.out

run: a.out
	./a.out
