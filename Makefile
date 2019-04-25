# Makefile for Board Games
# Date: 3/1/19

# USAGE:
# - to make all targets:
#      > make
# - to clean:
#      > make clean

CC=g++
CFLAGS=-std=c++11
TARGETS = ticTacToe

all:
	@make $(TARGETS)

ticTacToe: main.cpp Board.cpp minMaxAI.cpp bash.cpp
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm main $(TARGETS)
