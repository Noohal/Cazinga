
all: clean compile

compile:
	gcc -Wall -Wpedantic -Iinc -o caz $(wildcard src/*.c)

clean:
	rm caz

debug:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_out.txt ./caz
