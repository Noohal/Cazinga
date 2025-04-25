CC=gcc

SRC := $(wildcard src/*.c)

run:
	gcc -Iinc -o czg $(wildcard src/*c)
