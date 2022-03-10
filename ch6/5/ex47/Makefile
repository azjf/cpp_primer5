CPP = /usr/bin/g++

all: a.out
	./a.out

a.out: *.cpp
	$(CPP) $^ -o $@ -Wall -g

release.out: *.cpp
	$(CPP) $^ -D NDEBUG -o $@ -Wall -g
	./release.out

clean:
	rm a.out

run: a.out
	./a.out
