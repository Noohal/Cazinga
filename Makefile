
all: clean compile run

run:
	./caz

compile:
	gcc -O0 -g3 -Wall -Wpedantic -Iinc -o caz $(wildcard src/*.c)

clean:
	rm caz

debug:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_out.txt ./caz
